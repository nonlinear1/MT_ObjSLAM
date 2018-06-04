
#ifndef OBJECTNODE_H
#define OBJECTNODE_H
#include "OptimizableGraph/Vertex.h"

#include <string>
using OptimizableGraph::Vertex;

namespace ObjSLAM {


/**
  * class ObjectNode
  * 
  */

class ObjectNode : public Vertex
{
public:

	// Constructors/Destructors
	//  


	/**
	 * Empty Constructor
	 */
	ObjectNode ();

	/**
	 * Empty Destructor
	 */
	virtual ~ObjectNode ();

	// Static Public attributes
	//  

	// Public attributes
	//  


	// Public attribute accessor methods
	//  


	// Public attribute accessor methods
	//  


protected:

	// Static Protected attributes
	//  

	// Protected attributes
	//  

public:


	// Protected attribute accessor methods
	//  

protected:

public:


	// Protected attribute accessor methods
	//  

protected:


private:

	// Static Private attributes
	//  

	// Private attributes
	//  

	ObjSLAM::ObjectInstance object;
	ObjSLAM::ObjectView anchorCamView;
public:


	// Private attribute accessor methods
	//  

private:

public:


	// Private attribute accessor methods
	//  


	/**
	 * Set the value of object
	 * @param new_var the new value of object
	 */
	void setObject (ObjSLAM::ObjectInstance new_var)	 {
			object = new_var;
	}

	/**
	 * Get the value of object
	 * @return the value of object
	 */
	ObjSLAM::ObjectInstance getObject ()	 {
		return object;
	}

	/**
	 * Set the value of anchorCamView
	 * @param new_var the new value of anchorCamView
	 */
	void setAnchorCamView (ObjSLAM::ObjectView new_var)	 {
			anchorCamView = new_var;
	}

	/**
	 * Get the value of anchorCamView
	 * @return the value of anchorCamView
	 */
	ObjSLAM::ObjectView getAnchorCamView ()	 {
		return anchorCamView;
	}
private:


	void initAttributes () ;

};
} // end of package namespace

#endif // OBJECTNODE_H
