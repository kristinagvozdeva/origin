#include "money.h"
#include <iostream>

Money::Money(const long rubles, const unsigned short cents)
{
	this->setRubles(rubles);
	this->setCents(cents);
}

Money::Money(const Money& other) : rubles(other.rubles), cents(other.cents)
{
}


long Money::getRubles() const
{
	return this->rubles;
}

unsigned short Money::getCents() const
{
	return static_cast<unsigned short>(this->cents);
}

long Money::toCents() const
{
	if (getRubles() < 0) {
		return this->getRubles() * CENT_IN_RUB - getCents();
	}
	else {
		return this->getRubles() * CENT_IN_RUB + getCents();
	}
}

void Money::setRubles(long rubles)
{
	this->rubles = rubles;
}

void Money::setCents(unsigned short cents)
{
	if (cents < CENT_IN_RUB) {
		this->cents = static_cast<unsigned char>(cents);
	}
	else {
		this->cents = static_cast<unsigned char>(cents % CENT_IN_RUB);
		if (getRubles() < 0) {
			this->rubles -= long(cents / CENT_IN_RUB);
		}
		else {
			this->rubles += cents / CENT_IN_RUB;
		}
	}
}

Money Money::add(const Money& other) const
{
   const auto  cents = this->cents + other.cents;
   const auto  rubles = this->rubles + other.rubles;
   return Money(rubles, cents);
}

Money Money::sub(const Money& other) const
{
	if (toCents() >= other.toCents()) {
		const long coins = toCents() - other.toCents();
		return Money(coins / CENT_IN_RUB, abs(coins) % CENT_IN_RUB);
	}
	else
	{
		const long coins = other.toCents() - toCents();
		return Money(-1* coins / CENT_IN_RUB, abs(coins) % CENT_IN_RUB );
	}
}

double Money::div(const Money& other) const
{
	return double(toCents()) / double(other.toCents());
}

Money Money::divByDouble(const double n) const
{
	const long coins = toCents() / n;
	return Money(coins / CENT_IN_RUB, abs(coins) % CENT_IN_RUB);
}

Money Money::mulDouble(const double n) const
{

	const long coins = toCents() * n;
	return Money(coins / CENT_IN_RUB, abs(coins) % CENT_IN_RUB);
}

bool Money::isEqual(const Money& other) const
{
	return toCents()==other.toCents();
}

bool operator==(const Money& m1, const Money& m2)
{
	return m1.isEqual(m2);
}

std::istream& operator>>(std::istream& in, Money& m)
{
	long rubles;
	unsigned short cents;
	in >> rubles >> cents;
	m.setRubles(rubles);
	m.setCents(cents);
	return in;
}

std::ostream& operator<<(std::ostream& out, const Money& m)
{
	if (m.getCents() < 10) {
		out << m.getRubles() << ",0" << m.getCents() << " RUB";
	}
	else
	{
		out << m.getRubles() << "," << m.getCents() << " RUB";
	}
	return out;
}
