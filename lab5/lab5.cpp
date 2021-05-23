//3.  Функция вычисляет периметр треугольника.*/

#include <iostream>
#include <algorithm>
using namespace std;
/*
* \brief стороны и периметр треугольника
*/
struct triangle {
	double a;
	double b;
	double c;
	double p;
};

/*
* \brief  функция без спецификации исключений
*/
triangle per1(triangle& n) {
	if (n.a <= 0) {
		throw 'e';
	}
	if (n.b <= 0) {
		throw 'e';
	}
	if (n.c <= 0) {
		throw 'e';
	}
	n.p = n.a + n.b + n.c;
	return n;
};

/*
* \brief функция со спецификацией throw();
*/
triangle per2(triangle& n) throw(char) {
	if (n.a <= 0) {
		throw 'e';
	}
	if (n.b <= 0) {
		throw 'e';
	}
	if (n.c <= 0) {
		throw 'e';
	}
	n.p = n.a + n.b + n.c;
	return n;
};

/*
* \brief функция с конкретной спецификацией с подходящим стандартным исключением;
*/
triangle per3(triangle& n) throw(invalid_argument) {
	if (n.a <= 0) {
		throw invalid_argument("Error, a <= 0");
	}
	if (n.b <= 0) {
		throw invalid_argument("Error, b <= 0");
	}
	if (n.c <= 0) {
		throw invalid_argument("Error, c <= 0");
	}
	n.p = n.a + n.b + n.c;
	return n;
}

/*
* \brief  Независимый класс с полями-параметрами исключения
*/
class Exception
{
public:
	string s;
	Exception(string str)
	{
		s = str;
	}
	string what()
	{
		return s;
	}
};
/*
* \brief Спецификация с собственным реализованным исключением.
*/
triangle per4_1(triangle& n) throw(Exception) {
	if (n.a <= 0) {
		throw Exception("Error, a <= 0");
	}
	if (n.b <= 0) {
		throw Exception("Error, b <= 0");
	}
	if (n.c <= 0) {
		throw Exception("Error, c <= 0");
	}
	n.p = n.a + n.b + n.c;
	return n;
};

/*
* \brief Пустой класс
*/
class VoidException {};
/*
* \brief Спецификация с собственным реализованным исключением
*/
triangle per4_2(triangle& n) throw(VoidException) {
	if (n.a <= 0) {
		throw VoidException();
	}
	if (n.b <= 0) {
		throw VoidException();
	}
	if (n.c <= 0) {
		throw VoidException();
	}
	n.p = n.a + n.b + n.c;
	return n;
};

/*
* \brief Класс наследник от стандартного исключения с полями
*/
class InCorrectArgument : public exception
{
public:
	const char* what() const throw() {
		return "Error,  one or more argument <= 0\n";
	}
};
/*
* \brief Спецификация с собственным реализованным исключением
*/
triangle per4_3(triangle& n) {
	if (n.a <= 0) {
		throw InCorrectArgument();
	}
	if (n.b <= 0) {
		throw InCorrectArgument();
	}
	if (n.c <= 0) {
		throw InCorrectArgument();
	}
	n.p = n.a + n.b + n.c;
	return n;
};

int main()
{
	triangle t;
	cout << "Enter sides\na: ";
	cin >> t.a;
	cout << "b: ";
	cin >> t.b;
	cout << "c: ";
	cin >> t.c;
	cout << "Test error 1: ";
	try {
		per1(t);
		cout << "perimetr " << t.p << endl;
	}	
	//err 1
	catch (char) {
		cout << "Error 1\n";
	}
	cout << "Test error 2: ";
	try {
		per2(t);
		cout << "perimetr " << t.p << endl;
	}
	//error 2
	catch (char) {
		cout << "Error 2\n";
	}
	cout << "Test error 3: ";
	try {
		per3(t);
		cout << "perimetr " << t.p << endl;
	}
	//error 3
	catch (invalid_argument& e) {
		cout << e.what()<<endl;
	}
	cout << "Test error 4_1: ";
	try {
		per4_1(t);
		cout << "perimetr " << t.p << endl;
	}
	//error 4_1
	catch (Exception& e) {
		cout << e.what() << endl;
	}
	cout << "Test error 4_2: ";
	try {
		per4_2(t);
		cout << "perimetr " << t.p << endl;
	}
	//error 4_2
	catch (VoidException& e) {
		cout << "Error 4_2\n";
	}
	cout << "Test error 4_3: ";
	try {
		per4_3(t);
		cout << "perimetr " << t.p << endl;
	}
	//error 4_3
	catch (InCorrectArgument& e) {
		cout << e.what();
	}
}