#pragma once
#include <sstream>
/*Создать класс Money для работы с денежными суммами.
Число должно быть представлено двумя полями:
типа long для рублей и типа unsigned char - для копеек.
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой.
Реализовать сложение, вычитание, деление сумм,
деление суммы на дробное число, умножение на дробное число и операция сравнения.*/

/**
 * \brief класс Money для работы с денежными суммами
*/
class Money
{


public:
	/**
	 * \brief параметризованный конструктор со значениями по умолчанию
	 */
	Money(const long rubles=0, const unsigned short cents=0);
	/**
	 * \brief конструктор копирования
	 */
	Money(const Money& other);

	/**
	 * \brief конструктор перемещения
	 */
    Money (Money&& other) = default;

	/**
	 * \brief деструктор
	 */
	~Money() = default;

	/**
	 * \brief геттер для поля рубли
	 * \return рубли в типе long
	 */
	long getRubles() const;

	/**
	 * \brief геттер для поля копейки
	 * \return копейки в типе unsigned short
	 */
	unsigned short getCents() const;

	/**
	 * \brief метод сложения денежных величин
	 * \return новый объект Money
	 */
	Money add(const Money& other) const;

	/**
	 * \brief метод вычитания денежных величин
	 * \return новый объект Money
	 */
	Money sub(const Money& other) const;

	/**
	 * \brief метод деления денежных величин
	 * \return число double
	 */
	double div(const Money& other) const;

	/**
	 * \brief метод деления денежной величины на дробное число
	 * \return новый объект Money
	 */
	Money divByDouble(const double n=1.0) const;

	/**
	 * \brief метод умножения денежной величины на дробное число
	 * \return новый объект Money
	 */
	Money mulDouble(const double n=1.0) const;

    /**
	 * \brief метод, проверяющий равенство денежных величин
	 * \return утверждение истинно/ложно
	 */
	bool isEqual(const Money& other) const;

	/**
	 * \brief Перегруженный оператор сравнения денежных величин
	 */
	friend bool operator== (const Money& m1, const Money& m2);

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>> (std::istream& in, Money& m);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<< (std::ostream& out, const Money& m);

private:

	long rubles;								// рубли
	unsigned char cents;						// копейки
    const unsigned short CENT_IN_RUB = 100;		// копеек в рубле
	/**
	 * \brief метод перевода всей денежной величины в копейки
	 * \return копейки
	 */
	long toCents() const;

	/**
	 * \brief сеттер для поля рубли
	 */
	void setRubles(long rubles);

	/**
	 * \brief сеттер для поля копейки
	 */
	void setCents(unsigned short cents);

};
