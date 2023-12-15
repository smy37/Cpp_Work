#include "SigletonPattern.h"
#include "View.h"
#include <thread>

void View1Thread() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::vector<int> curMVmat;
	for (int i = 0; i < 16; i++) {
		curMVmat.push_back(i * 10 + 3);
	}
	CView view1(ModelViewCtrl::getMVctrl());
	view1.mvCtrl->setMVmatrix(curMVmat);
}
void View2Thread() {
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::vector<int> curMVmat;
	for (int i = 0; i < 16; i++) {
		curMVmat.push_back(i * -10 + 1);
	}
	CView view2(ModelViewCtrl::getMVctrl());
	curMVmat = view2.mvCtrl->getMVmatrix();

	for (int i = 0; i < 16; i++) {
		
		std::cout << curMVmat[i] << std::endl;
	}
}
//int main() {
//	std::thread t1(View1Thread);
//	std::thread t2(View2Thread);
//	t1.join();
//	t2.join();
//	
//	return 0;
//}