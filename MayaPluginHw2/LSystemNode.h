//#pragma once
//#include <maya/MPxCommand.h>
//#include <maya/MGlobal.h>
//
//#include <maya/MTime.h>
//#include <maya/MFnMesh.h>
//#include <maya/MPoint.h>
//#include <maya/MFloatPoint.h>
//#include <maya/MFloatPointArray.h>
//#include <maya/MIntArray.h>
//#include <maya/MDoubleArray.h>
//#include <maya/MFnUnitAttribute.h>
//#include <maya/MFnTypedAttribute.h>
//#include <maya/MFnPlugin.h>
//
//#include <maya/MPxNode.h>
//#include <maya/MObject.h>
//#include <maya/MPlug.h>
//#include <maya/MDataBlock.h>
//#include <maya/MFnMeshData.h>
//
//#include <maya/MIOStream.h>
//
//#define McheckErr(stat,msg)             \
//        if ( MS::kSuccess != stat ) {   \
//                cerr << msg;            \
//                return MS::kFailure;    \
//        }
//
//class LSystemNode : public MPxNode
//{
//public:
//	//Constructor 
//	LSystemNode();
//	//Destructor
//	virtual ~LSystemNode();
//	//Member Variables
//	uint nodeID;
//	static MObject time;
//	static MObject outputGeom;
//	//Member functions
//	static MStatus initialize();
//	virtual MStatus compute(const MPlug& plug, MDataBlock& data);
//	static void* creator() { return new LSystemNode(); }
//	virtual MStatus doIt(const MArgList& args);
//	virtual MStatus initializePlugin(MObject obj);
//	virtual MStatus uninitializePlugin(MObject obj);
//	MObject createMesh(const MTime& time, MObject& outData, MStatus& stat);
//};