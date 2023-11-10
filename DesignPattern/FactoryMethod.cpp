#include <iostream>

class TreeMenu {
public:
	virtual void draw() = 0;
	virtual void open() = 0;
	virtual void add() = 0;
	virtual void del() = 0;
	virtual ~TreeMenu() = default;
};

class TreeMenuDgn : public TreeMenu{
public:
	virtual void draw() {
		std::cout << "Design TreeMenu Draw" << std::endl;
	}
	virtual void open(){
		std::cout << "Design TreeMenu Open" << std::endl;
	}
	virtual void add() {
		std::cout << "Design TreeMenu Add" << std::endl;
	}
	virtual void del() {
		std::cout << "Design TreeMenu Del" << std::endl;
	}
};

class TreeMenuGPS : public TreeMenu {
public:
	virtual void draw() {
		std::cout << "GPS TreeMenu Draw" << std::endl;
	}
	virtual void open() {
		std::cout << "GPS TreeMenu Open" << std::endl;
	}
	virtual void add() {
		std::cout << "GPS TreeMenu Add" << std::endl;
	}
	virtual void del() {
		std::cout << "GPS TreeMenu Del" << std::endl;
	}
};

class TreeFactory {
public:
	virtual TreeMenu* createTreeMenu() = 0;
	virtual ~TreeFactory() = default;
};

class TreeFactoryDgn : public TreeFactory {
public:
	TreeMenu* createTreeMenu() override {
		return new TreeMenuDgn();
	}
};

class TreeFactoryGPS : public TreeFactory {
public:
	TreeMenu* createTreeMenu() override {
		return new TreeMenuGPS();
	}
};

void clientDraw(TreeFactory* treefac) {
	TreeMenu* tm = treefac->createTreeMenu();
	tm->draw();
}

void clientOpen(TreeFactory* treefac) {
	TreeMenu* tm = treefac->createTreeMenu();
	tm->open();
}

void clientAdd(TreeFactory* treefac) {
	TreeMenu* tm = treefac->createTreeMenu();
	tm->add();
}

void clientDel(TreeFactory* treefac) {
	TreeMenu* tm = treefac->createTreeMenu();
	tm->add();
}
//
//int main()
//{
//	TreeFactoryDgn dgnFactory;
//	clientDraw(&dgnFactory);
//	clientOpen(&dgnFactory);
//	clientAdd(&dgnFactory);
//
//	TreeFactoryGPS* gpsFactory = new TreeFactoryGPS();
//	clientDraw(gpsFactory);
//	clientOpen(gpsFactory);
//	clientAdd(gpsFactory);
//	clientDel(gpsFactory);
//}