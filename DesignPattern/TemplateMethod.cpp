#include "TemplateMethod.h"

int main(){
	FrontView* fV = new FrontView();
	RightView* rV = new RightView();
	fV->TemplateMethod();
	std::cout << "" << std::endl;
	rV->TemplateMethod();
}