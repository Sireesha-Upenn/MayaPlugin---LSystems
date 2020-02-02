#include "LSystemCmd.h"


#include <maya/MGlobal.h>
#include <list>
LSystemCmd::LSystemCmd() : MPxCommand()
{
}

LSystemCmd::~LSystemCmd() 
{
}

MStatus LSystemCmd::doIt(const MArgList& args )
{
	// message in Maya output window
    //cout<<"Implement Me!"<<endl;
	//std::cout.flush();

	// message in scriptor editor
	//MGlobal::displayInfo("Implement Me!");
	//POutput geometry 
	MGlobal::executeCommand("circle -c 0 0 0 -nr 0 1 0 -sw 360 -r 1 -d 3 -ut 0 -tol 0.01 -s 8 -ch 1;");
	MGlobal::executeCommand("curve -d 1 -p 5 0 0 -p 13 0 0 -k 0 - k 1; ");
	MGlobal::executeCommand("select -r nurbsCircle1 curve1; \n");
	MGlobal::executeCommand("extrude -ch true -rn false -po 1 -et 2 -ucp 1 -fpt 1 -upn 1 -rotation 0 - scale 1 - rsp 1 \"nurbsCircle1\" \"curve1\" ");
	
	double step_size;
	double angle;
	MString grammar;
	int iter;

	/*if (args.length() > 1 && args.length() < 5)
	{
		step_size = args.asDouble(0);
		angle = args.asDouble(1);
		grammar = args.asString(2);
		iter = args.asInt(3);
	}*/
	//Functions 
	MGlobal::executeCommand(" global proc importLSystem(string $filename, string $fileType) { file -import $filename; }");
	MGlobal::executeCommand(" global proc func() { fileBrowserDialog -m 0 -fc \"importLSystem\" -tm \"Select a text file \" -ft \"image\" -an \"filereader\" -om \"Import\" -tipMessage \"fileOpened\" ; }");
	MGlobal::executeCommand(" global proc func2() { string $filename[] = `fileDialog2 -fileMode 1 -caption \"Select a text file\"`; } ");
	MGlobal::executeCommand(" global proc filereader(string $filename){ int $fileid; $fileid = fopen($filename, \"r\"); }");
	// string $nextLine = `fgetline $fileid`; while(size($nextLine)>0){ `fgetline $fileid`; }
	//Window
	MGlobal::executeCommand("window  -menuBar true -title \"L-SYSTEMS \" -widthHeight 500 500 -titleBar true -backgroundColor 0.6 0.6 0.6 ; \n");
	MGlobal::executeCommand("columnLayout -adjustableColumn true; \n");
	MGlobal::executeCommand("button -label \"Browse\" -width 25 -height 25 -align \"right\" -command \"func2\"; ");
	MString lsystext;
	MGlobal::executeCommand(" scrollField -wordWrap true- text \" " + lsystext + " \" ;\n");
	//MGlobal::executeCommand(" text -label \"Iterations\";\n");
	MGlobal::executeCommand(" frameLayout -label \"LSystem Parameters\" -collapsable true -collapse false- borderStyle \"etchedIn\"; \n");
    //MGlobal::executeCommand("columnLayout -columnAttach \"both\" 5 -rowSpacing 5 -columnWidth 100 ; \n");
	MGlobal::executeCommand(" int $val1 = `floatSliderGrp -label \"Iterations\" -field true -minValue 0.0 -maxValue 10.0- fieldMinValue 0.0 - fieldMaxValue 100.0 -value 0` ; ");
	MGlobal::executeCommand("floatSliderGrp -label \"Default Step Size\" -field true -minValue 0.0 -maxValue 10.0- fieldMinValue 0.0 - fieldMaxValue 100.0 -value 0 ; ");
	MGlobal::executeCommand("floatSliderGrp -label \"Default Angle\" -field true -minValue 0.0 -maxValue 10.0- fieldMinValue 0.0 - fieldMaxValue 100.0 -value 0 ; ");
	MGlobal::executeCommand("setParent ..; \n");
	MGlobal::executeCommand(" scrollField -wordWrap true- text $val1 ;");
	MGlobal::executeCommand(" rowLayout -numberOfColumns 2 -columnWidth2 600 200 \n");
	MGlobal::executeCommand("setParent ..; \n");

	MGlobal::executeCommand(" rowLayout -numberOfColumns 2 -columnWidth2 200 200 \n");
	MGlobal::executeCommand("button -label \"Create\" -width 60 -height 30 -align \"right\" -command \"func2\"; ");
	MGlobal::executeCommand("button -label \"Cancel\" -width 60 -height 30 -align \"left\" -command \"func2\"; ");
	MGlobal::executeCommand("setParent ..; \n");
	
	MGlobal::executeCommand(" \n");
	
	MGlobal::executeCommand("showWindow");

	
    return MStatus::kSuccess;
}

