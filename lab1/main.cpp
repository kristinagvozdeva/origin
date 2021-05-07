#include "money.h"
#include <iostream>
using namespace std;

int main()
{
    auto m1 = Money();
    auto m2 = Money(123, 145);
    //заполнение полей объекта
    cin >> m1;
    cout << "Values of m1: " << m1 << endl;
    cout << "Values of m2: " << m2 << endl;
    cout << "m1 + m2: " << m1.add(m2) << endl;
    cout << "m1 - m2: " << m1.sub(m2) << endl;
    cout << "m1 / m2: " << m1.div(m2) << endl;
    cout << "m1 / 2.5: " << m1.divByDouble(2.5) << endl;
    cout << "m1 * 2.5: " << m1.mulDouble(2.5) << endl;
    //тест проверки на эквивалентность
    if (m1 == m2)
    {
        cout << "m2 is equal m1" << endl;
    }
    else
    {
        cout << "m2 is not equal m1" << endl;
    }
    return 0;
}

