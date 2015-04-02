#pragma once

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osgViewer\api\Win32/GraphicsWindowWin32>
#include <osgGA/TrackballManipulator>
#include <osgEarth/MapNode>
#include <osgEarthUtil/EarthManipulator>
#include <osgEarthUtil/Sky>
#include <osgEarth/ImageLayer>
#include "3DSmartCity.h"
#include "PipeStatisticHandler.h"
#include "HeadFiles.h"
#include "AddPipe.h"
#include "AddFlagDlg.h"
#include "AddClick.h"

#include "FlowDirectionDialog.h"

using namespace osgEarth;
class COSGObject
{
public:
	COSGObject(HWND hWnd);
	~COSGObject(void);
	void InitOSG();
	void InitSceneGraph();
	void InitCameraConfig();//��ʼ�����
	void PreFrameUpdate();//ǰ����
	void PostFrameUpdate();//����
	static void Render(void * ptr);//����̻߳��ⷽ��
	osg::ref_ptr<osgEarth::MapNode> mapNode;
	vector<string> layernames;
	osgEarth::ImageLayerVector imageLayerVec;

	osgViewer::Viewer *getViewer();
	void InitOsgEarth();
	void setChinaBoundariesOpacity(double opt);
	double getChinaBoundariesOpacity();
	void rmvChinaBounds();
	void addChinaBounds();

	void addPipe(string pipeName,string pointName);


	//biaohui--mark
	CAddFlagDlg *addlg;
	bool closeWindows;
	void addFlag();	
	osg::ref_ptr<osg::Group> mLabels;

	//�������ñ�־
	bool isDrawLineStart;
	osg::ref_ptr<osg::Group> mCSLine;

	//dc--����ͳ��-----------------------------------------------------------------
public:
	bool ifDoStatistic;
	StatisticDialog* pStatisticDlg;
	void initStatisticDlg();
	osg::Group* pRectNodeGroup;
	//dc----------------------------------------------------------------------------

	//dc--�������------------------------------------------------------------------
	FlowDirectionDialog* pFlowDirectionDlg;
	void initFlowDirectionDlg();
	//dc----------------------------------------------------------------------------

	//------wangsongwei  ����ģ�Ͳ����
	ModelLayerVector modelLayerVec;
	osg::ref_ptr<osg::Group> mPipeGroup;


private:
	HWND n_hWnd;//����һ�����
	osgViewer::Viewer * mViewer;
	osg::ref_ptr<osg::Group> mRoot;

	osg::ref_ptr<osgEarth::Util::EarthManipulator> em;
	osg::ref_ptr<osgEarth::ImageLayer> china_boundaries;
	//���� �ܵ�
private:
	map<string ,string> *pipes;
public:
	void pipeView(void);
	void buildingView(void);

};

