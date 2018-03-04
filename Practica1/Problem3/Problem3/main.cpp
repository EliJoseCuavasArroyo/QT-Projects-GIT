#include <iostream>

using namespace std;

int main()
/* El programa recibe un mes y un día de dicho mes.
 * El programa muestra en la terminal si la combinación de mes y día son válidos.
 */
{
    int month; // Variable la cual recibe el mes.
    int day; // Varaible la cual recibe el dia.
    cout << "Ingrese el mes: ";
    cin >> month;
    if ((month >= 1)&&(month <= 12)) // Si los meses no estan entre enero y diciembre, no los tomamos en cuenta.
    {
        cout << "Ingrese el dia: ";
        cin >> day;
        if (month == 2) // Si es febrero.
            // Febrero tiene desde 1 a 28 dias, en el caso de que sea bisiesto hasta 29 podria tener.
        {
            if ((day >= 1)&&(day <= 28)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else if (day == 29 ) cout << "La fecha: " << day << "/" << month << " es valida solo en bisiesto." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
        else if ((month == 4)||(month == 6)||(month == 9)||(month == 11)) // En el caso de que sea abril, junio, septiembre o noviembre.
            // Estos meses tienen de 1 a 30 dias.
        {
            if ((day >= 1)&&(day <= 30)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
        else // En el caso de los meses faltantes (enero, marzo, mayo, julio, agosto, octubre y diciembre), estos tiene de 1 a 31 dias.
        {
            if ((day >= 1)&&(day <= 31)) cout << "La fecha: " << day << "/" << month << " es valida." << endl;
            else cout << "La fecha " << day << "/" << month << " es invalida." << endl;
        }
    }
    else // En el caso de que el mes tomado no este dentro del rango estipulado.
    {
    cout << "El mes " << month << " es invalido." << endl;
    }
    return 0;
}

