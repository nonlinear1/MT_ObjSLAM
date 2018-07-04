//
// Created by khuang on 6/25/18.
//

#include "ObjectView_New.h"

namespace ObjSLAM{

ObjCameraPose ObjectView_New::getCameraPose(){
  return camera_Pose;
}


void ObjectView_New::setCameraPose(ObjCameraPose _pose)
{
  camera_Pose = _pose;
}

void ObjectView_New::setListOfObjects_old() {

  std::cout << "Setting Obj List..." << std::endl;

  std::vector<int> labelIndexVector;

  for (int i = 0; i < segmentation_Mask->dataSize; i++) {

    int labelIndex = segmentation_Mask->GetElement(i, MEMORYDEVICE_CPU);


    //if vector does not contain this label
    //then it is a new label
    //add it to vector and create the map entry with ITMView

    if (std::find(labelIndexVector.begin(), labelIndexVector.end(), labelIndex) == labelIndexVector.end()) {
      //add index in vector
      labelIndexVector.push_back(labelIndex);
//      std::cout << "Added index " << labelIndex << std::endl;

      //add index in map
      ObjectClassLabel label(labelIndex, std::to_string(labelIndex));
      auto *new_obj_instance = new ObjSLAM::ObjectInstance(label);
      auto *single_obj_ITMView = new ITMLib::ITMView(calibration, imgSize_rgb, imgSize_d, false);

      //Init size of depth in ITMView
      single_obj_ITMView->depth->ChangeDims(imgSize_d);
      //Init size of rgb in ITMView
      single_obj_ITMView->rgb->ChangeDims(imgSize_rgb);

      //Set value of the first pixel
      single_obj_ITMView->depth->GetData(MEMORYDEVICE_CPU)[i]=this->depth_Image->GetData(MEMORYDEVICE_CPU)[i];
      single_obj_ITMView->rgb->GetData(MEMORYDEVICE_CPU)[i]=this->rgb_Image->GetData(MEMORYDEVICE_CPU)[i];

      Object_View_Tuple object_view_tuple(new_obj_instance, single_obj_ITMView);
      obj_map.insert(std::pair<int, Object_View_Tuple>(labelIndex, object_view_tuple));
    }
      //if this label already seen
    else {

      Object_View_Tuple view_tuple = obj_map.find(labelIndex)->second;
      //<0> is ObjectInstance <1> is ITMView
//      std::cout << "DEBUG" << std::endl;
      std::get<1>(view_tuple)->depth->GetData(MEMORYDEVICE_CPU)[i]=this->depth_Image->GetData(MEMORYDEVICE_CPU)[i];
      std::get<1>(view_tuple)->rgb->GetData(MEMORYDEVICE_CPU)[i]=this->rgb_Image->GetData(MEMORYDEVICE_CPU)[i];

    }
  }
}


void ObjectView_New::setListOfViews() {

  for(int i=0; i  < segmentation_Mask->dataSize; i++){
//    if(segmentation_Mask->GetElement(i, MEMORYDEVICE_CPU))
  }

}


std::map<int, Object_View_Tuple> ObjectView_New::getObjMap(){
  return obj_map;
}


}