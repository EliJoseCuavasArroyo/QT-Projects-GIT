#include <iostream>

using namespace std;

bool multipliex(int, int); // Prototipo de funcion, que nos dice si un numero tiene un producto el cual de cierto numero.
int main()
/* El programa recibe un número.
 * El programa calcula el mínimo común múltiplo de todos los números enteros entre 1 y el número ingresado.
 */
{
    int num, mcm, mcmmax=1;
    bool imaginebreaker=false;
    // Definimos la variable num, la cual es el numero ingresado por el usuario
    // Definimos la variable mcm, la cual va a ser los posibles minimo como un multiplo.
    // Definimos la variable mcmmax, la cual podra un limite al mcm.
    cout << "Ingrese el numero: ";
    cin >> num;
    for(int i=1;i<=num;i++)
    {
        mcmmax = mcmmax*i; // Todos los numeros de 1 a num, tienen este comun multipo
    }
    for (int i=1;i<=mcmmax;i++)
    {
        if (imaginebreaker == true) break; // En el caso de que encontremos al minimo comun multiplo, dejamos de probar mas mimimos comun multiplos.
        mcm = i;
        for(int j=1;j<=num;j++) // Revisamos que todos los numeros tienga dicho minimo comun multiplo
        {
            if ((multipliex(j, mcm)) == false) // Si al menos uno no lo tiene, probamos con otro.
            {
                imaginebreaker = false;
                break;
            }
            imaginebreaker = true; // Mientras todos tengan dicho minimo comun multiplo, el imaginebreaker sera verdadero.
        }
    }
    cout <<  "El minimo comun multiplo es: " << mcm << endl;
    return 0;
}
bool multipliex(int numero, int producto) // Esta funcion va multiplicando numero por numero hasta ver si existe producto
{
int count = 1;
while ((numero*count) <= (producto)) // Si el producto llega a ser mayor de lo esperado, quiere decir que no existe un factor que multipicado por numero de producto.
    {
    if ((numero*count) == (producto)) return true; // Si es igual, entonces existe un numero que multilicado por la variable numero de producto.
    count = count+1;
    }
return false;
}
