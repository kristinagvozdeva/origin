#include "Money.h"
#include <iostream>
#include <sstream>
using namespace std;
class Money
{
public:
	Money() {};
	Money(long rubles, unsigned int cents)
	{
		this->rubles = rubles;

	};

	~Money();


	long GetRubles()
	{
		return rubles;
	};


	unsigned int GetCents()
	{
		return cents;
	};


	/**
	 * \brief  метод, возвращающий  сумм
	 * \return сложение сумм
	 */
	Money& GetSumm(Money& first, Money& second) const
	{
		Money answer(13, 12);
		answer.rubles = (first.rubles + second.rubles) + (first.cents * second.cents);
		return answer;
	};


	/**
	 * \brief  метод, возвращающий сумм
	 * \return вычитание сумм
	 */
	Money& GetSub(Money& first, Money& second) const
	{
		Money answer(13, 12);
		answer.rubles = (first.rubles + second.rubles) - (first.cents * second.cents);
		return answer;

	};


	/**
	 * \brief  метод, возвращающий деленние сумм
	 * \return деление сумм
	 */
	Money& DivisionSumm(Money& first, Money& second)
	{
		Money answer(13, 12);
		answer.rubles = (first.rubles / second.rubles) / (first.cents + second.cents);
		return answer;
	};


	/**
	 * \brief  метод, позвол¤ющий провести деление суммы на дробное число
	 * \return результат
	 */
	Money& DivisionSummFraction(Money& first, Money& second)
	{
		Money answer(13, 12);
		answer.rubles = ((first.rubles + second.rubles) + (first.cents + second.cents)) / 3, 14;
		return answer;
	};


	/**
	 * \brief  метод, позволяющий провести умножение суммы на дробное число
	 * \return результат
	 */
	Money& MultiplicationFraction(Money& first, Money& second)
	{
		Money answer(13, 12);
		answer.rubles = ((first.rubles + second.rubles) + (first.cents + second.cents)) / 3, 14;
		return answer;
	};


	/**
	 * \brief  метод, позвол¤ющий провести сравнение сумм
	 * \return результат
	 */
	bool AreEqual()
	{

	};

private:

	long rubles;

	unsigned int cents;
};