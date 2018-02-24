#include <iostream>

using namespace std;

int main()
/* El programa que recibe constantemente números hasta que se ingrese el número cero.
 * El programa muestra en la terminal el mayor de todos los números ingresados.
 */
{
    int num, mayor=0;
    // Definimos la variable num, la cual recibira constantemente los numeros ingresados por el usuario hasta que llegue a cero.
    // Definimos la variable mayor, la cual guardara el numero mayor entre todos los que envio el usuario.
    cout << "Ingrese el numero: ";
    cin >> num;
    while (num != 0) // Mientras el usuario no ingrese cero.
    {
        cout << "Ingrese el numero: ";
        cin >> num;
        if (num > mayor) // Actualizamos la variable mayor, en el caso de que el usuario ingrese un numero mayor, en comparacion a los ingresados anteriormente.
        {
            mayor = num;
        }
    }
    cout << "El numero mayor fue: " << mayor << endl;
    return 0;
}
