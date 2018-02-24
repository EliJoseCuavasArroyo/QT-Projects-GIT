#include <iostream>

using namespace std;

int main()
/* El programa recibe un número N.
 * Entrega la suma de todos los números entre 0 y N (incluyéndose el mismo).
 */
{
    unsigned int num, sum=0; //Inicializamos las variables.
    // La variable sum llevara la sumatoria de todos los numeros entre 0 y num.
    // La variable num es el numero de referencia al cual se le hara la sumatoria.
    cout << "Ingrese el numero: ";
    cin >> num; // Capturamos la referencia.
    for(unsigned int i=1;i<=num;i++){
        sum = sum+i;
        }
    cout << "La sumatoria entre 0 y "<< num << " " << "es: " << sum << endl;
    return 0;
}
