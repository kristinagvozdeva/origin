#include "liq.h"
int main()
{
	Liquid kola;
	std::cin >> kola;
	kola.reassignment_density(900);
	kola.change_density(100);
	std::cout<< kola;
	Alcohol vodka;
	std::cin >> vodka;
	vodka.reassignment_n(30);
	vodka.change_n(10);
	std::cout << vodka;
	Alcohol whiskey("jack daniel's", 980, 40);
	std::cout << whiskey;
	return 0;
}