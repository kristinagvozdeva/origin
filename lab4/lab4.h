//  Написать программу, в которой описана иерархия классов: геометрические фигуры (круг, прямоугольник, треугольник).
//Реализовать методы вычисления площади и периметра фигуры.
//Продемонстрировать работу всех методов классов, предоставив пользователю выбор типа фигуры для демонстрации.

#include <iostream>
#include <cmath>
/**
* \brief Класс фигура
*/
class Figure {

protected:
	/**
	* \brief Деструктор
	*/
    ~Figure() = default;
	/**
	* \brief Периметр
	*/
    double perimeter = 0;
	/**
	* \brief Площадь
	*/
    double area = 0;
    static constexpr double PI = 2 * asin(double(1));
	/**
	* \brief метод проверки ввода
	*/
    double checkValue(const double value) const;
public:
	/**
	* \brief виртуальное объявление метода нахождения периметра
	*/
    virtual double getPerimeter() = 0;
	/**
	* \brief виртуальное объявление метода нахождения площади
	*/
    virtual double getArea() = 0;
    /**
    * \brief Перегруженный оператор вывода
    */
    friend std::ostream& operator<< (std::ostream& out, const Figure& figure);
};

/**
* \brief Класс круг
*/
class Circle : public Figure {
private:
	/**
    * \brief поле - радиус круга
    */
    double r;
    static constexpr double TWO_PI = 4 * asin(double(1));
public:
	/**
    * \brief Конструктор по умолчанию
    */
    Circle() = default;
	/**
    * \brief Конструктор параметризованный
    */
    Circle(const double r);
	/**
	* \brief метод нахождения периметра
	*/
    double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Circle& circle);
};

/**
* \brief Класс прямоугольник
*/
class Rectangle : public Figure {
private:
	/**
    * \brief  поля - стороны прямоугольника
    */
    double a, b;
public:
	/**
    * \brief Конструктор по умолчанию
    */
    Rectangle() = default;
	/**
    * \brief Конструктор параметризованный
    */
    Rectangle(const double a, const double b);
	/**
	* \brief метод нахождения периметра
	*/
    double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Rectangle& rectangle);
};

/**
* \brief Класс треугольник
*/
class Triangle : public Figure {
private:
	/**
    * \brief  поля - стороны треугольника
    */
    double a, b, c;
    /**
    * \brief  метод проверки существования треугольника
    */
    void checkTrValues(const double a, const double b, const double c) const;
public:
	/**
    * \brief Конструктор по умолчанию
    */
    Triangle() = default;
	/**
    * \brief Конструктор параметризованный
    */
    Triangle(const double a, const double b, const double c);
	/**
	* \brief метод нахождения периметра
	*/
    double getPerimeter() override;
	/**
	* \brief метод нахождения площади
	*/
    double getArea() override;
    /**
     * \brief Перегруженный оператор ввода
     */
    friend std::istream& operator>> (std::istream& in, Triangle& triangle);
};

