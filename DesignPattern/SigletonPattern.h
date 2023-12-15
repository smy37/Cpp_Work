#pragma once
#include <vector>
#include <iostream>
#include <mutex>
class ModelViewCtrl
{
private:
	static ModelViewCtrl* mvCtrl;
	static std::mutex mutex_;

	std::vector<int> mvMatrix;
public:
	ModelViewCtrl() {
		mvMatrix.resize(16);
		std::fill(mvMatrix.begin(), mvMatrix.end(), 0);
	};
public:
	ModelViewCtrl(int x, int y) {
		mvMatrix.resize(x);
		std::fill(mvMatrix.begin(), mvMatrix.end(), y);
	};
public:
	static ModelViewCtrl* getMVctrl() {
		//std::lock_guard<std::mutex> lock(mutex_);
		if (mvCtrl == nullptr) {
			mvCtrl = new ModelViewCtrl();
			std::cout << "Make!" << std::endl;
		}
		return mvCtrl;
	}

	std::vector<int> getMVmatrix();
	void setMVmatrix(const std::vector<int>& vcMat);

};