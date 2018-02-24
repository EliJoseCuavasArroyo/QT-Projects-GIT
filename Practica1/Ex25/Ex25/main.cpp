#include <iostream>

using namespace std;

int main()
/* El programa recibe un número.
 * El programa muestra en la terminal la cantidad de dígitos de aquel numero.
 */
{
    int num, count=0;
    // Definimos la variable num cuyos digitos vamos a determinar su cantidad de digitos.
    // Definimos la variable count, la cual contara los digitos del numero num.
    cout << "ingrese el numero: ";
    cin >> num;
    cout << "El numero " << num << " tiene ";
    while ((num*10)/10 != 0) // En este ciclo le iremos quitando digito por digito al numero num, hasta que se haga cero.
    {
        count = count+1;// Iremos contando cada vez que le quitamos un digito.
        num = num/10;// Aqui le quitamos un digito al numero num.
    }
    cout << count << " Digitos" << endl;
    return 0;
}
