#include "lab4.h"
#include <iostream>
#include <cmath>

double Figure::checkValue(const double value) const
{
	if (value <= 0)
		throw std::out_of_range("Non-positive value");
	return value;
}

std::ostream& operator<<(std::ostream& out, const Figure& figure)
{
	out << "Perimetr " << figure.perimeter << std::endl << "Area " << figure.area << std::endl;
	return out;
}

Circle::Circle(const double r)
{
	this->r = checkValue(r);
}

double Circle::getPerimeter()
{
	this->perimeter = TWO_PI * this->r;
	return this->perimeter;
}

double Circle::getArea()
{
	this->area = PI * this->r * this->r;
	return this->area;
}

Rectangle::Rectangle(const double a, const double b)
{
	this->a = checkValue(a);
	this->b = checkValue(b);
}

double Rectangle::getPerimeter()
{
	this->perimeter = 2 * (this->a + this->b);
	return  this->perimeter;
}

double Rectangle::getArea()
{
	this->area = this->a * this->b;
	return this->area;
}

 void Triangle::checkTrValues(const double a, const double b, const double c) const
 {
	 checkValue(a);
	 checkValue(b);
	 checkValue(c);
	 if (a >= b + c || b >= a + c || c >= a + b)
		 throw std::out_of_range("Triangle does not exist");
 }

 Triangle::Triangle(const double a, const double b, const double c)
{
	checkTrValues(a, b, c);
	this->a = checkValue(a);
	this->b = checkValue(b);
	this->c= checkValue(c);
}

 double Triangle::getPerimeter()
 {
	 this->perimeter = this->a + this->b + this->c;
	 return this->perimeter;
 }

 double Triangle::getArea()
 {
	 double p = getPerimeter() / 2;
	 this->area = sqrt(p * (p - this->a) * (p - this->b) * (p - this->c));
	 return this->area;
 }

 std::istream& operator>>(std::istream& in, Circle& circle)
 {
	 double r;
	 in >> r;
	 circle = Circle(r);
	 return in;
 }

 std::istream& operator>>(std::istream& in, Rectangle& rectangle)
 {
	 double a, b;
	 in >> a >> b;
	 rectangle = Rectangle(a, b);
	 return in;
 }

 std::istream& operator>>(std::istream& in, Triangle& triangle)
 {
	 double a, b, c;
	 in >> a >> b >> c;
	 triangle = Triangle(a, b, c);
	 return in;
 }
