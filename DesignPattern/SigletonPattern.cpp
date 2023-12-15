#include "SigletonPattern.h"
#include <memory>
#include <vector>
ModelViewCtrl* ModelViewCtrl::mvCtrl = nullptr;
std::mutex ModelViewCtrl::mutex_;

std::vector<int> ModelViewCtrl::getMVmatrix() {
	return mvMatrix;
}
void ModelViewCtrl::setMVmatrix(const std::vector<int>& vcMat) {
	for (int i = 0; i < vcMat.size(); i++) {
		mvMatrix[i] = vcMat[i];
	}
}

//int main() {
//	std::unique_ptr<ModelViewCtrl> mvCtrl = std::make_unique<ModelViewCtrl>(5, 4);
//	mvCtrl->getMVctrl();
//	ModelViewCtrl* testCtrl = mvCtrl.release();
//	ModelViewCtrl* testCtrl2 = mvCtrl.get();
//	// 이하 로직 //
//	return 0;
//}

