#pragma once
#include <iostream>
#include <vector>


//  Implementation

class Renderer {
public:
	virtual void draw(double x, double y, std::vector<int> rgb) = 0;
};

class RenderFilled : public Renderer {
	void draw(double x, double y, std::vector<int> rgb) override;
};

class RenderTransparent : public Renderer {
	void draw(double x, double y, std::vector<int> rgb) override;
};

class RenderSharply : public Renderer {
	void draw(double x, double y, std::vector<int> rgb) override;
};

class RenderDotLine : public Renderer {
	void draw(double x, double y, std::vector<int> rgb) override;
};


// Abstraction

class Type {
protected:
	Renderer* m_imply;
public:
	Type(Renderer* imply) : m_imply(imply) {}

	virtual void execute() = 0;
};

class BeamType : public Type {
	std::vector<int> cord;
	double mat;
public:
	BeamType(Renderer* imply, std::vector<int> coordination, double material) : Type(imply), cord(coordination), mat(material) {}
	void execute();
};

class ColumnType : public Type {
	std::vector<int> cord;
	double mat;
public:
	ColumnType(Renderer* imply, std::vector<int> coordination, double material) : Type(imply), cord(coordination), mat(material) {}
	void execute();
};

class LinkType : public Type {
	std::vector<int> cord;
	double mat;
	float tens;
public:
	LinkType(Renderer* imply, std::vector<int> coordination, double material, float tension) : Type(imply), cord(coordination), mat(material), tens(tension) {}
	void execute();
};

class BoundaryType : public Type {
	std::vector<int> cord;
	double mat;
	int str;
public:
	BoundaryType(Renderer* imply, std::vector<int> coordination, double material, int strength) : Type(imply), cord(coordination), mat(material), str(strength) {}
	void execute();
};




