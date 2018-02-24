#include <iostream>

using namespace std;

int main()
/* El programa recibe un carácter, si es una letra la debe convertir de mayúscula a minúscula y viceversa.
 * El programa muestra la letra convertida en la terminal.
 */
{
   char letra; // Definimos la variable que va a recibir la letra ingresada por el usuario.
    cout << "Ingrese una letra valida: ";
    cin >> letra;
    if ((letra >= 65)&&(letra <= 90)) // En el caso de que sea mayuscula.
    {
        letra = letra+32; //La convertimos a minuscula.
        cout << "Letra convertida: " << letra <<endl;
    }
    else if ((letra >= 97)&&(letra <= 122)) // En el caso de que sea minuscula
    {
        letra = letra-32; // La convertimos a mayuscula.
        cout << "Letra convertida: " << letra <<endl;
    }
    else
    {
     cout << "No es una letra" << endl; // En el caso de que no haya ingersado una letra.
    }
    return 0;
}
