//#include "LSystemNode.h"
//
//LSystemNode::LSystemNode()
//{
//}
//
//
//LSystemNode::~LSystemNode()
//{
//}
//
//MStatus LSystemNode::doIt(const MArgList& args)
//{
//	MGlobal::displayInfo("NODEEEEEEEEEEEEEEEEEEE!");
//	return MStatus::kSuccess;
//}
//MStatus LSystemNode::initializePlugin(MObject obj)
//{
//	MStatus   status = MStatus::kSuccess;
//	MFnPlugin plugin(obj, "MyPluginNode", "1.0", "Any");
//
//	//Register Node
//	status = plugin.registerNode("LsystemNode", LSystemNode::nodeID, LSystemNode::creator, LSystemNode::initialize);
//	if (!status) {
//		status.perror("registerNode");
//		return status;
//	}
//
//	return status;
//}
//MStatus LSystemNode::uninitializePlugin(MObject obj)
//{
//	MStatus   status = MStatus::kSuccess;
//	MFnPlugin plugin(obj);
//
//	status = plugin.deregisterCommand("LSystemNode");
//	status = plugin.deregisterNode(LSystemNode::nodeID);
//	if (!status) {
//		status.perror("deregisterNode");
//		return status;
//	}
//	return status;
//}
//
//MStatus LSystemNode::initialize()
//{
//	MStatus returnStatus;
//	
//	MFnNumericAttribute* angle = 0;
//	MFnNumericAttribute* stepSize = 0;
//	MFnTypedAttribute grammar;
//	
//	MFnUnitAttribute* UAtime;
//	MFnTypedAttribute geom;
//	
//	// Create and add an input MFnTypedAttribute for the grammar file. You can specify files relative to the plug-in .mll location using MFnPlugin::loadPath()
//
//	LSystemNode::time = UAtime->create("time", "tm", MFnUnitAttribute::kTime, 0.0, &returnStatus);
//
//	McheckErr(returnStatus, "ERROR creating LSystemNode time attribute\n");
//
//	LSystemNode::outputGeom = geom.create("output geometry", "out", MFnData::kMesh, &returnStatus);
//
//	McheckErr(returnStatus, "ERROR creating LSystemNode outGeom attribute\n");
//
//	geom.setStorable(false);
//
//	returnStatus = addAttribute(LSystemNode::time);
//	McheckErr(returnStatus, "ERROR adding time attribute\n");
//
//	returnStatus = addAttribute(LSystemNode::outputGeom);
//	McheckErr(returnStatus, "ERROR adding outputMesh attribute\n");
//
//	returnStatus = attributeAffects(LSystemNode::time, LSystemNode::outputGeom);
//
//	McheckErr(returnStatus, "ERROR in attributeAffects\n");
//
//	return MS::kSuccess;
//
//}
//MStatus LSystemNode::compute(const MPlug& plug, MDataBlock& data)
//{
//	return MS::kSuccess;
//}
//MObject LSystemNode::createMesh(const MTime& time, MObject& outData, MStatus& stat)
//{
//	return outData;
//}