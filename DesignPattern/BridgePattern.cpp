#include "BridgePattern.h"


void RenderFilled::draw(double x, double y, std::vector<int> rgb){
	std::cout << "Using Filled surface & Ordinary Line" << std::endl;
	std::cout << "Surface = Filled" << std::endl;
	std::cout << "Line = Default" << std::endl;
	std::cout << x << ", " << y << ", " << rgb[0]<<":" << rgb[1]<<":" << rgb[2] << std::endl;
};

void RenderTransparent::draw(double x, double y, std::vector<int> rgb) {
	std::cout << "Using Transparent surface & Ordinary Line" << std::endl;
	std::cout << "Surface = Transparent" << std::endl;
	std::cout << "Line = Default" << std::endl;
	std::cout << x << ", " << y << ", " << rgb[0] << ":" << rgb[1] << ":" << rgb[2] << std::endl;
};

void RenderSharply::draw(double x, double y, std::vector<int> rgb) {
	std::cout << "Using Sharp Line" << std::endl;
	std::cout << "Surface = Default" << std::endl;
	std::cout << "Line = Sharp" << std::endl;
	std::cout << x << ", " << y << ", " << rgb[0] << ":" << rgb[1] << ":" << rgb[2] << std::endl;
};

void RenderDotLine::draw(double x, double y, std::vector<int> rgb) {
	std::cout << "Using Dash LIne" << std::endl;
	std::cout << "Surface = Default" << std::endl;
	std::cout << "Line = Dashed" << std::endl;
	std::cout << x << ", " << y << ", " << rgb[0] << ":" << rgb[1] << ":" << rgb[2] << std::endl;
};



void BeamType::execute() {
	m_imply->draw(cord[0], cord[1], { (int)mat, (int)mat + 5, (int)mat - 5 });
}

void ColumnType::execute() {
	m_imply->draw(cord[0], cord[1], { (int)mat, (int)mat + 5, (int)mat - 5 });
}

void LinkType::execute() {
	m_imply->draw(cord[0], cord[1], { (int)mat, (int)mat + 5*(int)tens, (int)mat - 5 * (int)tens });
}

void BoundaryType::execute() {
	m_imply->draw(cord[0], cord[1], { (int)mat, (int)mat + 5 * (int)str, (int)mat - 5 * (int)str });
}



//int main() {
////
////	Renderer* implFill = new RenderFilled;
////	Type* type = new BeamType(implFill, {0, 10}, 1.8);
////	type->execute();
////	std::cout << std::endl;
////	
////
////	Renderer* implSharp = new RenderSharply;
////	type = new ColumnType(implSharp, { 0, 10 }, 1.8);
////	type->execute();
////	std::cout << std::endl;
////
////	Renderer* implTrans = new RenderTransparent;
////	type = new BoundaryType(implTrans, { 0, 10 }, 1.8, 125);
////	type->execute();
////	std::cout << std::endl;
////
////	Renderer* implDot = new RenderDotLine;
////	type = new LinkType(implDot, { 0, 10 }, 1.8, 999);
////	type->execute();
////	std::cout << std::endl;
////
//	return 0;
//}