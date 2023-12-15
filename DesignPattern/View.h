#pragma once
#include "SigletonPattern.h"
class CView
{
public:
	ModelViewCtrl* mvCtrl;
	CView(ModelViewCtrl* mvc) : mvCtrl(mvc) {};
};