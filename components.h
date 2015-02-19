#ifndef _skilLibComponents
#define _skilLibComponents

#include <stdio.h>
#include <vector>
#include <GLFW/glfw3.h>
#include <string>
#include "skilLib.h"
#include "systems.h"
#include "messages.h"

const int COMPONENT_NONE = 0;
const int COMPONENT_COLOR = 1;
const int COMPONENT_POSITION = 2;
const int COMPONENT_DIMENSIONS = 3;
const int COMPONENT_TEXTURE = 4; //not yet iomplemented
const int COMPONENT_VECTOR = 5;
const int COMPONENT_VELOCITY = 6;

class NullComponent : public Component{
public:
	NullComponent();
	Component *spawn(std::string, std::string);
};

class Color : public Component{
public:
	Color();
	Color(float gr, float gg, float gb, float ga);
	Component *spawn(std::string, std::string);
	float getR();
	float getG();
	float getB();
	float getA();
	void setR(float get);
	void setG(float get);
	void setB(float get);
	void setA(float get);
protected:
	float r, g, b, a;
};

class Position : public Component{
public:
	Position();
	Position(float gx, float gy);
	Component *spawn(std::string, std::string);
	float getX();
	float getY();
	void setX(float get);
	void setY(float get);
protected:
	float x, y;
};

class Dimensions : public Component{
public:
	Dimensions();
	Dimensions(int gw, int gh);
	Component *spawn(std::string, std::string);
	int getWidth();
	int getHeight();
	void setWidth(int get);
	void setHeight(int get);
protected:
	int width, height;
};

//Class Vector yet implemented. Wait until back on the ground and wifi is available.
class Vector : public Component{
public:
	Vector();
	Vector(float gmag, float gdir);
	Vector(float gmag, float gdir, int gid);
	Component *spawn(std::string, std::string);
	float getMagnitude();
	float getDirection();
	float getXComponent();
	float getYComponent();
	void setMagnitude(float gmag);
	void setDirection(float gdir);
protected:
	void updateComponents();
	float magnitude;
	float direction;
	float xComponent;
	float yComponent;
};

#endif
