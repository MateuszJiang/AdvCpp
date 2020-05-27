#pragma once

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

class Ellipse
{
private:
	double x;
	double y;
	double a;
	double b;
	double angle;
public:
	void Move(int nx, int ny) { x = nx; y = ny; }
	virtual double Area() const { return 3.14159 * a * b; }
	virtual void Rotate(double nangle) { angle += nangle; }
	virtual void Scale(double sa, double sb) { a *= sa; b *= sb; }
};

class Circle : public Ellipse
{

};



#endif