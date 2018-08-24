//
// Created by khuang on 8/22/18.
//

#ifndef MT_OBJSLAM_TEDDYREADER_H
#define MT_OBJSLAM_TEDDYREADER_H

#include <External/InfiniTAM/InfiniTAM/ITMLib/Engines/ViewBuilding/ITMViewBuilderFactory.h>
#include <External/InfiniTAM/InfiniTAM/ITMLib/Engines/ViewBuilding/CPU/ITMViewBuilder_CPU.h>
#include "DatasetReader.h"
#include "External/InfiniTAM/InfiniTAM/ITMLib/Objects/Camera/ITMCalibIO.h"

class TeddyReader : public DatasetReader{
 private:
  string calib_path;

 public:
  TeddyReader(string _path, Vector2i _imgSize):DatasetReader(_path, _imgSize){
    img_number=0;
    calib_path = path+"calib.txt";
    readCalib();
    viewBuilder = new ITMLib::ITMViewBuilder_CPU(*calib);
    cout<<"Created TeddyReader Path "<<path<<endl;
  }

  int readNext();

  ObjSLAM::ObjShortImage *ConvertToRealDepth(ObjSLAM::ObjFloatImage *depth);

  bool readCalib();
};

#endif //MT_OBJSLAM_TEDDYREADER_H