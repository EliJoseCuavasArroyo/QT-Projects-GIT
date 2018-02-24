#include <iostream>

using namespace std;

int main()
/* En la serie de Fibonacci, cada número es la suma de los 2 anteriores e inicia con 1 y 1. Ej: 1, 1, 2, 3, 5, 8, ....
 * El programa recibe un numero "num" entero y positivo.
 * El programa entrega la suma de todos los números pares en la serie de Fibonacci menores a num.
 */
{
    int num, sum=0, fibonacci=1, antfibonacci=0, fibonaccicopy=0;
    // Inicializamos la variable num, la cual es el numero de referencia del cual los numeros de la serie de fibonacci deben ser menores.
    // Inicializamos la variable sum, la cual llevara la suma de los numeros pares de la serie de fibonacci.
    // Inicializamos la variable fibonacci, la cual llevara el numero actual a la serie de fibonacci.
    // Inicializamos la variable antfibonacci, la cual llevara el numero anterior al actual de la serie de fibonacci.
    // Inicializamos la variable fibonaccicopy, la cual llevara la copia del actual numero de fibonacci, para luego pasarlo a antfibonacci despues que avanze un numero la serie de fibonacci.
    cout << "Ingrese el numero: ";
    cin >> num; // Capturamos el numero de referencia.
    while((fibonacci+antfibonacci) < num) // Mientras el numero siguiente en la serie de fibonacci sea menor a la referencia.
    {
    fibonaccicopy = fibonacci; // Copiamos al fibonacci.
    fibonacci = antfibonacci+fibonacci; // Actualizamos fibonacci.
    antfibonacci = fibonaccicopy; // Guardamos al anterior fibonacci.
    if (fibonacci%2 == 0) // Si el actual numero de la serie de fibonacci es par.
        {
        sum = sum+fibonacci; // Lo sumamos.
        }
    }
    cout << "El resultado de la suma es: " << sum << endl;
    return 0;
}
