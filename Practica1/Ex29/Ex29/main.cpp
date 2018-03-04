#include <iostream>

using namespace std;

/* Se emplean las siguientes librerias para generar en numero aleatorio dentro de un
 rango establecido. */

#include <stdio.h>
/* printf, scanf, puts, NULL */

#include <stdlib.h>
/* srand, rand */

#include <time.h>
/* time */

int main()
/* El programa adivina un número A (entre 0 y 100) seleccionado por el usuario (el número NO se ingresa al programa).
 * El programa imprimira en pantalla un número B y el usuario usará los símbolos `>', `<' y `=' para indicarle al programa si B es mayor, menor o igual que A.
 * El programa imprimira un nuevo número B, con base en simbolo ingresado por el usuario, y repetira el proceso hasta acertar el número seleccionado por usuario.
 */
{

srand (time(NULL)); // Tomara en cuenta el criterio del tiempo para generar un numero en la funcion rand (Esta operacion es propia de la maquina).

int num; // El numero a adivinar (No influye directamente en el programa).
unsigned short int numguess; // Variable la cual tomara los posibles resultados.
unsigned short int limitmenor = 0; // Limite inferior de los posibles resultados.
unsigned short int limitmayor = 100; // Limite mayor de los posibles resultados.
char obtion = 88; // Variable que recibira los simbolos  '>', '<' o '='.
numguess = rand() % (limitmayor-limitmenor+1) + limitmenor; // Tomamos un numero al azar con la funcion rand.
cout << "Ingrese el numero que el programa tiene que adivinar: ";
cin >> num;

if ((num >= 0)&&(num <= 100)){

while (2>1)
    {
    cout << numguess << endl; // Mostramos el posible numero.
    cout << "Ingrese uno de los simbolos '>', '<' o '=', para definir la situacion de la cercania del numero presentado al numero que se desea adivinar: ";
    cin >> obtion; // Recibimos el simbolo ingresado por el usuario.
    if (obtion == 62) limitmayor = numguess-1; // Si el simbolo ingresado es '>', significa que " numguess > num ", entonces actualizamos el limite superior.
    else if (obtion == 60) limitmenor = numguess+1;// Si el simbolo ingresado es '<', significa que " numguess < num ", entonces actualizamos el limite inferior.
    else if (obtion == 61) break; // Si el simbolo ingresado es '=', significa que el programa adivino el numero.
    else cout << "Obcion invalida, intente de nuevo" << endl;
    numguess = rand() % (limitmayor-limitmenor+1) + limitmenor; // Tomamos un nuevo numero deacuerdo al los nuevos rangos establecidos.
    }

}

else
    {
    cout << "Error" << endl;
    }
return 0;
}

