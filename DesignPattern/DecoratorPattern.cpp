#pragma once
#include <iostream>
#include <string>
#include <memory>
//Component
class ModelView {
public:
	virtual void getMVMatrix() = 0;
	virtual double getPixelCol() = 0;
	virtual ~ModelView() = default;
};

class BaseModelView : public ModelView {
public:
	void getMVMatrix() override {
		std::cout << "Simple matrix" << std::endl;
		return;
	}
	double getPixelCol() override {
		std::cout << "RGB(128, 143, 137)" << std::endl;
		return 0;
	}
};

// Decorator
class CustomizeView : public ModelView {
protected:
	ModelView* customizeView;
public:
	CustomizeView(ModelView* mView) : customizeView(mView) {}

	void getMVMatrix() override {
		return customizeView->getMVMatrix();
	}

	double getPixelCol() override {
		return customizeView->getPixelCol();
	}

	virtual ~CustomizeView() {
		delete customizeView;
	}
};

class GrayScaleView : public CustomizeView {
public:
	GrayScaleView(ModelView* mView) : CustomizeView(mView) {}
	void getMVMatrix() override {
		customizeView->getMVMatrix();
		std::cout << "with gray scale transform matrix" << std::endl;
		return;
	}
	double getPixelCol() override {
		customizeView->getPixelCol();
		std::cout << "X RGB(1.7, 1.9, 1.7)" << std::endl;
		return 0;
	}
};

class BrightView : public CustomizeView {
public:
	BrightView(ModelView* mView) : CustomizeView(mView) {}
	void getMVMatrix() override {
		customizeView->getMVMatrix();
		std::cout << "with lighter transform matrix" << std::endl;
		return;
	}
	double getPixelCol() override {
		customizeView->getPixelCol();
		std::cout << "X RGB(100, 101, 120)" << std::endl;
		return 0;
	}
};

int main() {
	ModelView* myView = new BaseModelView();
	/*myView->getMVMatrix();
	myView->getPixelCol();*/
	std::cout << "" << std::endl;
	myView = new GrayScaleView(myView);
	/*myView->getMVMatrix();
	myView->getPixelCol();*/
	std::cout << "" << std::endl;
	myView = new BrightView(myView);
	/*myView->getMVMatrix();
	myView->getPixelCol();*/

	myView = new GrayScaleView(myView);
	myView->getMVMatrix();
	myView->getPixelCol();
	std::cout << "" << std::endl;

	delete myView;
	return 0;
}