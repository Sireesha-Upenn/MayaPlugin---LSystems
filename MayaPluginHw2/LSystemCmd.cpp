#include "LSystemCmd.h"
#include <maya/MGlobal.h>
#include <maya/MArgList.h>
#include <list>
#include <string.h>
#include <iostream>

using namespace std;
LSystemCmd::LSystemCmd() : MPxCommand()
{
}

LSystemCmd::~LSystemCmd() 
{
}

MStatus LSystemCmd::doIt(const MArgList& args)
{
	// message in Maya output window
	//cout<<"Implement Me!"<<endl;
	//std::cout.flush();

	// message in scriptor editor
	//MGlobal::displayInfo("Implement Me!");
	//POutput geometry 

	


	//-----------------Output Geometry---------------// 
	MGlobal::executeCommand("circle -c 0 0 0 -nr 0 1 0 -sw 360 -r 1 -d 3 -ut 0 -tol 0.01 -s 8 -ch 1;");
	MGlobal::executeCommand("curve -d 1 -p 5 0 0 -p 13 0 0 -k 0 - k 1; ");
	MGlobal::executeCommand("select -r nurbsCircle1 curve1; \n");
	MGlobal::executeCommand("extrude -ch true -rn false -po 1 -et 2 -ucp 1 -fpt 1 -upn 1 -rotation 0 - scale 1 - rsp 1 \"nurbsCircle1\" \"curve1\" "); 
	MGlobal::executeCommand(" curve -d 1 -p 0 0 0 - p -5 8 9 -k 0 - k 1 - name curve1;  select - r nurbsCircle1 curve1; extrude - ch true - rn false - po 1 - et 2 - ucp 1 - fpt 1 - upn 1 - rotation 0 - scale 1 - rsp 1 \"nurbsCircle1\" \"curve1\"; ");
	//-----------------------------------------------//
	
	//Variables in Maya for Grammar, stepSize, angle and iterations
	MGlobal::executeCommand("global string $grammar;");
	MGlobal::executeCommand("global float $stepSize;");
	MGlobal::executeCommand("global float $angle;");
	MGlobal::executeCommand("global int $iter;");
	//---------------CMD LINE ARGS-------------------//
	double step_size;
	double angle;
	MString grammar;
	int iter;

	if (args.length() > 1 && args.length() < 5)
	{
		step_size = args.asDouble(0);
		angle = args.asDouble(1);
		grammar = args.asString(2);
		iter = args.asInt(3);

		l.setDefaultAngle(angle);
		l.setDefaultStep(step_size);

		string step = std::to_string(step_size);
		MString ss = step.c_str();
		string ang = std::to_string(angle);
		MString angl = ang.c_str();
		string it = std::to_string(iter);
		MString ite = it.c_str();
		
		MGlobal::executeCommand("$grammar = \"" + grammar + " \" \n");
		MGlobal::executeCommand("$stepSize = " + ss + "  \n");
		MGlobal::executeCommand("$angle = " + angl + "  \n");
		MGlobal::executeCommand("$iter = " + ite + "  \n");
		
		MGlobal::executeCommand("print ($grammar); print ($stepSize); print ($angle); print ($iter); ");

	}
	//----------------------------------------------//

	
    return MStatus::kSuccess;
}

