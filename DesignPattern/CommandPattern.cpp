#include "CommandPattern.h"
#include "iostream"


void CTextOut::SettingBeamStress() {
	std::cout << "Setting!" << std::endl;
}
void CTextOut::Font4BeamStress() {
	std::cout << "Font!" << std::endl;
}
void CTextOut::TextOutBeamStress(int x, int y) {
	std::cout << x << ", " << y << std::endl;
}

void CTextOut::SettingBeamDeform() {
	std::cout << "Setting!" << std::endl;
}
void CTextOut::Font4BeamDeform() {
	std::cout << "Font!" << std::endl;
}
void CTextOut::TextOutBeamDeform(int x, int y) {
	std::cout << x << ", " << y << std::endl;
}


void CTextOut::ExecuteAll(){
	for (int i = 0; i < this->Commands.size(); i++) {
		this->Commands[i]->execute();
	}
}


//int main() {
//	CTextOut* pTextOut = new CTextOut();
//	CmdFont4BeamDeform* cmd1 = new CmdFont4BeamDeform();
//	pTextOut->AddCommand(cmd1);
//	CmdSettingBeamDeform* cmd2 = new CmdSettingBeamDeform();
//	pTextOut->AddCommand(cmd2);
//	CmdTextOutBeamDeform* cmd3 = new CmdTextOutBeamDeform();
//	pTextOut->AddCommand(cmd3);
//
//	CmdSettingBeamStress* cmd4 = new CmdSettingBeamStress();
//	pTextOut->AddCommand(cmd4);
//	CmdFont4BeamStress* cmd5 = new CmdFont4BeamStress();
//	pTextOut->AddCommand(cmd5);
//	CmdTextOutBeamStress* cmd6 = new CmdTextOutBeamStress();
//	pTextOut->AddCommand(cmd6);
//
//	pTextOut->ExecuteAll();
//}
