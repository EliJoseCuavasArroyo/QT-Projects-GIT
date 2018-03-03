#include <iostream>

using namespace std;

int main()
{
    int month;
    int day;
    cout << "Ingrese el mes: ";
    cin >> month;
    if ((month >= 1)&&(month <= 12))
    {
        cout << "Ingrese el dia: ";
        cin >> day;
        if (month == 2)
        {
            if ((day >= 1)&&(day <= 28)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else if (day == 29 ) cout << "La fecha: " << day << "/" << month << " es valida solo en bisiesto." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
        else if ((month == 4)||(month == 6)||(month == 9)||(month == 11))
        {
            if ((day >= 1)&&(day <= 30)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
        else
        {
            if ((day >= 1)&&(day <= 31)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
    }
    else
    {
    cout << "El mes " << month << " es invalido." << endl;
    }
    return 0;
}

