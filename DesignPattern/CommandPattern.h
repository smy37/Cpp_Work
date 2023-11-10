#include <iostream>
#include <vector>
class Command;
class CTextOut
{
public:
	std::vector<Command*> Commands;

	void AddCommand(Command* cmd) {
		Commands.push_back(cmd);
	}
	void ClearCommand() {
		Commands.clear();	
	}

	void ExecuteAll();

	void SettingBeamStress();
	void Font4BeamStress();
	void TextOutBeamStress(int x, int y);

	void SettingBeamDeform();
	void Font4BeamDeform();
	void TextOutBeamDeform(int x, int y);
};

class Command
{
protected:
	CTextOut* m_TextOut;
public:
	virtual void execute() = 0;
};

class CmdSettingBeamStress : public Command
{
	virtual void execute()
	{
		m_TextOut->SettingBeamStress();
	}
};

class CmdFont4BeamStress : public Command
{
public:
	virtual void execute()
	{
		m_TextOut->Font4BeamStress();
	}
};

class CmdTextOutBeamStress : public Command
{
public:
	int m_LocX;
	int m_LocY;
	virtual void execute()
	{
		m_TextOut->TextOutBeamStress(m_LocX, m_LocY);
	}
};

class CmdSettingBeamDeform : public Command
{
public:
	virtual void execute()
	{
		m_TextOut->SettingBeamDeform();
	}
};

class CmdFont4BeamDeform : public Command
{
public:
	virtual void execute()
	{
		m_TextOut->Font4BeamDeform();
	}
};

class CmdTextOutBeamDeform : public Command
{
public:
	int m_LocX;
	int m_LocY;
	virtual void execute()
	{
		m_TextOut->TextOutBeamDeform(m_LocX, m_LocY);
	}
};



