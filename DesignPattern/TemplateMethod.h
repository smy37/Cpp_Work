#pragma once
#include <memory>
#include <iostream>

class ViewBase {
public:
	void TemplateMethod()  {
		MulRotationMatrix(std::move(this->ViewMatrix));
		MulTranslateMatrix(this->ViewMatrix);
		ApplyCliping(this->ViewMatrix);
		ApplyZoomFit(this->ViewMatrix);
		SetColor();
	}
	
protected:
	std::unique_ptr<int[]> ViewMatrix = std::make_unique<int[]>(16);
	virtual void MulRotationMatrix(std::unique_ptr<int[]> VM) = 0;
	virtual void MulTranslateMatrix(std::unique_ptr<int[]>& VM) = 0;
	virtual void SetColor() {};
	void ApplyCliping(std::unique_ptr<int[]>& VM) {
		std::cout << "Apply Cliiping on VM" << std::endl;
	}
	void ApplyZoomFit(std::unique_ptr<int[]>& VM) {
		std::cout << "Apply ZoomFit on VM" << std::endl;
	}
};

class FrontView : public ViewBase{
protected:
	virtual void MulRotationMatrix(std::unique_ptr<int[]> VM)  {
		std::cout << "Multiply Front Rotation Matrix on VM" << std::endl;
	}
	virtual void MulTranslateMatrix(std::unique_ptr<int[]>& VM) {
		std::cout << "Multiply Front Translation Matrix on VM" << std::endl;
	}
};

class RightView : public ViewBase{
	virtual void MulRotationMatrix(std::unique_ptr<int[]> VM) {
		std::cout << "Multiply Right Rotation Matrix on VM" << std::endl;
	}
	virtual void MulTranslateMatrix(std::unique_ptr<int[]>& VM) {
		std::cout << "Multiply Right Translation Matrix on VM" << std::endl;
	}
	virtual void SetColor() {
		std::cout << "Set Red Color" << std::endl;
	};
};

