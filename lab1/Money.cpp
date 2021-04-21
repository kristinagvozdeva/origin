#include "money.h"
#include <iostream>

Money::Money(const long rubles, const unsigned short cents)
{	
	setRubles(rubles);
	setCents(cents);
}

Money::Money(const Money& other) : cents(other.cents), rubles(other.rubles)
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
		return this->getRubles() * CENTSINRUB - getCents();
	}
	else {
		return this->getRubles() * CENTSINRUB + getCents();
	}
	
}

void Money::setRubles(long rubles)
{
	this->rubles = rubles;
}

void Money::setCents(unsigned short cents)
{
	if (cents < CENTSINRUB) {
		this->cents = static_cast<unsigned char>(cents);
	}
	else {
		this->cents = static_cast<unsigned char>(cents % CENTSINRUB);
		if (getRubles() < 0) {
			this->rubles -= long(cents / CENTSINRUB);
		}
		else {
			this->rubles += cents / CENTSINRUB;
		}
	}
}

Money& Money::addMoney(const Money& other) const
{
	const long coins = toCents() + other.toCents();	
	const auto sum = new Money(coins / CENTSINRUB, abs(coins) % CENTSINRUB);
	return *sum;
}

Money& Money::subMoney(const Money& other) const
{
	if (toCents() >= other.toCents()) {
		const long coins = toCents() - other.toCents();
		const auto sub = new Money(coins / CENTSINRUB, abs(coins) % CENTSINRUB);
		return *sub;
	}
	else
	{
		const long coins = other.toCents() - toCents();
		const auto sub = new Money(-1 * coins / CENTSINRUB, abs(coins) % CENTSINRUB);
		return *sub;
	}
}

Money& Money::divMoney(const Money& other) const
{
	const long coins = toCents() / abs(other.toCents()); //так как делим копейки, остатком пренебрегаем
	const auto div = new Money(coins / CENTSINRUB, abs(coins) % CENTSINRUB);
	return *div;
}

Money& Money::divByDouble(const double n) const
{
	const long coins = toCents() / n; //так как делим копейки, остатком пренебрегаем
	const auto div = new Money(coins / CENTSINRUB, abs(coins) % CENTSINRUB);
	return *div;
}

Money& Money::mulDouble(const double n) const
{
	
	const long coins = toCents() * n; //так как умножаем копейки, остатком пренебрегаем
	const auto mul = new Money(coins / CENTSINRUB, abs(coins) % CENTSINRUB);
	return *mul;
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
	in >> rubles;
	m.setRubles(rubles);
	in >> cents;
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
