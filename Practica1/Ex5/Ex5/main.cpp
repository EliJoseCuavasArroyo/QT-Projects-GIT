#include <iostream>

using namespace std;
/* El programa recibe dos numeros enteros y positivos, los cuales va a dividir.
 * Si de su division resulta un numero real no entero.
 * Se redondeara el numero al numero entero mas cercano.
 * El programa entregara el resultado de su division redondeada(si es que es necesario).
 */
int main()
{
    int divisor, dividendo; //Inicializamos las variales la cuales haran la operacion de la division.
    float division; //Inicializamos una variable la cual registrara la diferencia entre las divisiones (una entera y otra real).
    cout << "Ingrese el numero del dividendo: ";
    cin >> dividendo; //Capturamos la variable del dividendo.
    cout << "Ingrese el numero del divisor: ";
    cin >> divisor; //Capturamos la variable del divisor.
    if (divisor == 0)//Una division por cero esta indeterminada, por lo tanto si el divisor es cero.
        {
        cout << "Error en las variables de entrada"; // El programa presentara el error.
        }
    else //En el caso en el que no haya problemas cin el divisor.
        {
        division = ((float(dividendo)/float(divisor))-(dividendo/divisor));
        cout << "Resultado: " << dividendo << "/" << divisor << "=";
        if (division > 0.5) //Si la diferencia entre la real y la entera es mayor a 0.5.
            {
            cout << (dividendo/divisor)+1 << endl; //Se redonda al numero entero siguiente mas cercano a su division real.
            }
        else //Si no es mayor su diferencia a 0.5.
            {
            cout << (dividendo/divisor) << endl; //Se redondea al numero entero anterior mas cercano a su division real.
            }
        }
    return 0;
}
