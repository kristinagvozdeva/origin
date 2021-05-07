#pragma once;
#include <iostream>
#include <sstream>
#include "liq.h"

std::string toString(float& r) {

	std::ostringstream ost;

	ost << r;

	return ost.str();

}

bool Liquid::correct_density(float density){
	if (density >= 700 && density <= 1360)
		return 0;
	else
		return 1;
}

Liquid::Liquid(const std::string name, const float density) {
	if (correct_density(density))
		throw "e";
	set_density(density);
	set_name(name);
}

Liquid::Liquid(const Liquid& other) {
	name = other.name;
	density = other.density;
}

std::string Liquid::get_name() const {
	return this->name;
}

void Liquid::set_name(const std::string name) {
	this->name = name;
}

float Liquid::get_density() const {
	return this->density;
}

void Liquid::set_density(const float density) {
	this->density = density;
}

void Liquid::change_density(const float r) {
	if (correct_density(density + r)) {
		throw "e";
	}
	else {
		density += r;
	}
}

void Liquid::reassignment_density(const float r) {
	if (correct_density(r))
		throw "e";
	set_density(r);
}

std::istream& operator>>(std::istream& in, Liquid& l)
{
	float density;
	std::string name;

	in >> name >> density;
	l = Liquid(name, density);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Liquid& l)
{
	out << "name: " << l.name << std::endl << "density: " << l.density << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Alcohol& a)
{
	float density, n;
	std::string name;

	in >> name >> density >> n;
	a = Alcohol(name, density, n);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Alcohol& a)
{
	out << "name: " << a.name << std::endl << "density: " << a.density << std::endl << "n: " << a.n << std::endl;
	return out;
}

bool Alcohol::correct_n(const float n) const
{
	if (n >= 0 && n <= 100)
		return 0;
	else
		return 1;
}

Alcohol::Alcohol(const std::string name, const float density, const float n) {
	if (correct_density(density))
		throw "e";
	if (correct_n(n))
		throw "e";
	set_name(name);
	set_density(density);
	set_n(n);
}

Alcohol::Alcohol(const Alcohol& other) {
	this->name = other.name;
	this->density = other.density;
	this->n = other.n;
}

float Alcohol::get_n() const {
	return this->n;
}

void Alcohol::set_n(const float n) {
	this->n = n;
}

void Alcohol::change_n(const float r) {

	if (get_n() + r < 0)
		throw "e";
	set_n(get_n() + r);
}

void Alcohol::reassignment_n(const float r) {
	if (correct_n(r))
		throw "e";
	set_n(r);
}
