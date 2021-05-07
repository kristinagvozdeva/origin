#pragma once;
#include <iostream>
#include <sstream>

class Liquid {

protected:

	std::string name;
	float density;

	/**
	 * \brief Метод проверки допустимости значений Плотность жидкостей (диапазон 700-1360 кг/м3)
	 */
	bool correct_density(const float density);

	/**
	 * \brief Сеттер поля name
	 */
	void set_name(const std::string name);

	/**
	 * \brief Сеттер поля density
	 */
	void set_density(const float density);

public:
	/**
	 * \brief Конструктор по умолчанию
	 */
	Liquid() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Liquid(const std::string name, const float density);

	/**
	 * \brief Конструктор копирования
	 */
	Liquid(const Liquid& other);

	/**
	 * \brief Деструктор
	 */
	~Liquid() = default;

	/**
	 * \brief Геттер поля  name
	 */
	std::string get_name() const;

	/**
	 * \brief Геттер поля density
	 */
	float get_density() const;	
	
	/**
	 * \brief Метод переназначения плотности
	 */
	void change_density(const float r);

	/**
	 * \brief Метод замены плотности
	 */
	void reassignment_density(const float r);

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>>(std::istream& in, Liquid& l);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<<(std::ostream& out, const Liquid& l);
};

class Alcohol : Liquid {

private:
	float n;

	/**
	 * \brief Метод проверки допустимости значений крепости - концентрация спирта в объеме. Т. Е. его процентное содержание (диапазон от 0 до 10)
	 */
	bool correct_n(const float n) const;
	
	/**
	 * \brief Сеттер поля n
	 */
	void set_n(const float n);

public:
	/**
	 * \brief Конструктор по умолчанию
	 */
	Alcohol() = default;

	/**
	 * \brief Параметризованный конструктор
	 */
	Alcohol(const std::string name, const float density, const float n);

	/**
	 * \brief Конструктор копирования
	 */
	Alcohol(const Alcohol& other);

	/**
	 * \brief Деструктор
	 */
	~Alcohol() = default;

	/**
	 * \brief Геттер поля n
	 */
	float get_n() const;	

	/**
	 * \brief Метод переназначения концентрации
	 */
	void change_n(const float r);

	/**
	 * \brief Метод замены концентрации
	 */
	void reassignment_n(const float r);

	/**
	 * \brief Перегруженный оператор ввода
	 */
	friend std::istream& operator>>(std::istream& in, Alcohol& a);

	/**
	 * \brief Перегруженный оператор вывода
	 */
	friend std::ostream& operator<<(std::ostream& out, const Alcohol& a);
};