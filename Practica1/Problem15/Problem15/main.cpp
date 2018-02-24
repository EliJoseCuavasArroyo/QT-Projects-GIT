#include <iostream>

using namespace std;

int main()
/* El programa recibe un numero positivo y entero.
 * El programa entrega la suma de los numeros en la diagonal de la mariz nxn espiral.
 */
{
    int range, sum=1, criterion=0, num=1;
        /*
         -En la variable sum, mantendremos la suma de los números de la matriz diagonal.
         -La variable criterion es el criterio de aumento por el cual tomará cada número.
         -La variable num son los números que cumplen el criterio de aumento y deben agregarse.
        */
    cout << "Ingrese un numero impar positivo, el cual sea el rango de la matriz par: ";
    cin >> range; // Capturamos el numero del rango de la matiz nxn.
    while (num<(range*range)) // Mientras los numero que cumplan el criterio de aumento sean menores al numero maximo.
    {
        criterion = criterion+2; // El criterio de incremento, aumenta de 2 en 2.
        for (int i =0;i<4;i++) //Se toman los siguientes 4 números que cumplen con el criterio de aumento.
        {
            num = num+criterion; // Cada numero debe tener una diferencia del criterio de incremento.
            sum = sum+num; // Acumulamos el numero en la variable sum.
        }
    }
    cout << "La suma de los numeros en la diagonal de la matriz es: " << sum << endl;
    return 0;
}
