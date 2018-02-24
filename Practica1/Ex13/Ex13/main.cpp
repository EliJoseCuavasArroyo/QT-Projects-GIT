#include <iostream>

using namespace std;

int main()
/* El programa recibe un numero entero positivo.
 * El programa muestra sus divisores en la terminal (Incluyendo el mismo).
 */
{
    unsigned int num; // Definimos la variable a recibir.
    cout << "Ingrese el numero: ";
    cin >> num; // Captuamos en numero de referencia de digitos en la variable num.
    cout << "Los divisores de " << num << " son: " << endl;
    for (unsigned i=1;i<=((num/2)+1);i++){ // Miramos cuales son su posible divisores.
        // El maximo divisor de un numero es su mitad (en el casos de los pares) o antes de la mitad (en el caso de los impares).
        if (num%i == 0){ // En el caso de que sea divisor.
        cout << i << endl; // Lo mostramos en pantalla.
        }
    }
    cout << num << endl; // Mostramos obviamente el mismo numero ya que tambien es divisor de el mismo.
    return 0;
}
