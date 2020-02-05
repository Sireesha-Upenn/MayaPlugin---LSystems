#include "LSystemNode.h"
#include "LSystem.h"
#include "LSystemCmd.h"
#include <maya\MPoint.h>
#include <maya\MPointArray.h>
#include <maya\MFnMesh.h>
#include <maya\MTypeId.h>
typedef std::pair<vec3, vec3> Branch;

//Static variables 
uint LSystemNode::nodeID;
MObject LSystemNode::time;
MObject LSystemNode::outputGeom;
MObject LSystemNode::angle;
MObject LSystemNode::stepSize;
MObject LSystemNode::grammar;



LSystemNode::LSystemNode() 
{}

LSystemNode::~LSystemNode()
{}

MStatus LSystemNode::doIt(const MArgList& args)
{
	MGlobal::displayInfo("NODEEEEE!");
	return MStatus::kSuccess;
}


MStatus LSystemNode::initialize()
{
	MStatus returnStatus;
	
	MFnUnitAttribute UAtime;
	MFnTypedAttribute geom;
	MFnNumericAttribute m_angle;
	MFnNumericAttribute m_stepSize;
	MFnTypedAttribute m_grammar;
	// Create and add an input MFnTypedAttribute for the grammar file. You can specify files relative to the plug-in .mll location using MFnPlugin::loadPath()

	LSystem l;

	time = UAtime.create("time", "tm", MFnUnitAttribute::kTime, 0.0, &returnStatus);

	McheckErr(returnStatus, "ERROR creating LSystemNode time attribute\n");

	outputGeom = geom.create("output geometry", "out", MFnData::kMesh, &returnStatus);

	McheckErr(returnStatus, "ERROR creating LSystemNode outGeom attribute\n");

	//grammar
	grammar = m_grammar.create("grammar", "gr", MFnData::kString, &returnStatus);
	//stepsize
	stepSize = m_stepSize.create("stepSize", "ss", MFnNumericData::kFloat , 0.0, &returnStatus);
	//angle 
	angle = m_angle.create("angle", "ang", MFnNumericData::kFloat , 0.0, &returnStatus);

	geom.setStorable(false);

	returnStatus = addAttribute(time);
	McheckErr(returnStatus, "ERROR adding time attribute\n");

	returnStatus = addAttribute(outputGeom);
	McheckErr(returnStatus, "ERROR adding outputMesh attribute\n");
	
	returnStatus = addAttribute(grammar);
	McheckErr(returnStatus, "ERROR adding grammar attribute\n");

	returnStatus = addAttribute(stepSize);
	McheckErr(returnStatus, "ERROR adding stepSize attribute\n");

	returnStatus = addAttribute(angle);
	McheckErr(returnStatus, "ERROR adding angle attribute\n");

	returnStatus = attributeAffects(time, outputGeom);
    McheckErr(returnStatus, "ERROR in attributeAffects\n");

	return MS::kSuccess;

}
MStatus LSystemNode::compute(const MPlug& plug, MDataBlock& data)
{
	MStatus returnStatus;
	MFnMesh meshFS;

	if (plug == outputGeom) {
		/* Get time */
		MDataHandle timeData = data.inputValue(time, &returnStatus);
		McheckErr(returnStatus, "Error getting time data handle\n");
		MTime time = timeData.asTime();

		MDataHandle outputHandle = data.outputValue(outputGeom, &returnStatus);
		McheckErr(returnStatus, "ERROR getting Geom data handle\n");
		
		MDataHandle g = data.inputValue(grammar, &returnStatus);
		McheckErr(returnStatus, "ERROR getting Geom data handle\n");
		MString grammar = g.asString();

		MFnMeshData dataCreator;
		MObject newOutputData = dataCreator.create(&returnStatus);
		McheckErr(returnStatus, "ERROR creating outputData");

		std::vector<Branch> b;
		//Loop and create nodes by calling createNode LSystemNode;  in MEL 
		l.process(10, b);

		MPointArray points;
		MIntArray faceCounts;
		MIntArray faceConnects;
		for (int i = 0; i < b.size(); i++)
		{
			MPoint p1 = MPoint(b[i].first[0], b[i].first[1], b[i].first[2], 1.0);
			MPoint p2 = MPoint(b[i].second[0], b[i].second[1], b[i].second[2], 1.0);
			CylinderMesh c(p1,p2);
			c.appendToMesh(points, faceCounts, faceConnects);
		}
		MObject newMesh = meshFS.create(points.length(), faceCounts.length(), points, faceCounts, faceConnects,newOutputData);

		//c.getMesh(time, newOutputData, returnStatus);
		McheckErr(returnStatus, "ERROR");

		outputHandle.set(newOutputData);
		data.setClean(plug);

	}
	else
	{
		return MS::kUnknownParameter;
	}

	return MS::kSuccess;
}
