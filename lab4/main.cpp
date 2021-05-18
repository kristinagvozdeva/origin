#include <iostream>
#include "lab4.h"
using namespace std;
// функция вывода меню
void menu()
{
    string list[3] = { "Circle", "Rectangle", "Triangle" };
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter " << i << " for test " << list[i] << endl;
    }
    cout << "Enter -1 for exit" << endl;
}

int main() {
    while (true)
    {       
        auto c = Circle();
        auto r = Rectangle();
        auto t = Triangle();
        int i;
        menu();
        cin >> i;
        switch (i)
        {
            case 0:
            {
                cin >> c;
                c.getArea();
                c.getPerimeter();
                cout << c;
                break;
            }
            case 1:
            {
                cin >> r;
                r.getArea();
                r.getPerimeter();
                cout << r;
                break;
            }
            case 2:
            {
                cin >> t;
                t.getArea();
                t.getPerimeter();
                cout << t;
                break;
            }
            case -1:
            {
                return 0;
            }
        }
    }
}