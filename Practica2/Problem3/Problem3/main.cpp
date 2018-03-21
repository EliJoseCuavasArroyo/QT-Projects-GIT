#include <iostream>

using namespace std;
#define limit 50 // Establecemos un limite para el ingreso de una cadena de caracteres.

int strlen(char*); // Esta funcion se encarga de entregar la cantidad de palabras que tiene un caracter.

bool same(char* ,char*); // La funcion compara dos cadenas de caracteres y si son iguales; entrega un true en el caso de que lo sean, false en el caso contrario.

/* Prueba
 * Consiste en que el usuario ingresa dos cadenas de caracteres.
 * Si son iguales, el programa dice que son iguales.
 * Si no lo son, el programa dice que no lo son.
 * Deben tener en cuenta que si se tiene en cuenta la diferencia entre las mayusculas y las minusculas.
 */

int main()
{
    cout << " Bienvenido a una prueba de caja blanca" << endl;
    cout << " Consiste en que usted ingresa dos cadenas de caracteres" << endl;
    cout << " Si son iguales, el programa dice que son iguales" << endl;
    cout << " Si no lo son, el programa dice que no lo son" << endl;
    cout << " Debe tener en cuenta que el programa tiene en cuenta que existe diferencia entre las mayusculas y las minusculas" << endl;
    cout << endl;

    // Definimos dos cadenas de caracteres con sus respectivos limites.

    char str1[limit];
    char str2[limit];
    cout << "Ingrese el primer caracter: ";
    cin >> str1;
    cout << "Ingrese el segundo caracter: ";
    cin >> str2;

    if (strlen(str1) == strlen(str2)) // Si no tienen la misma longitud, evidentemente no son iguales.
        {
        if (same(str1, str2) == true) cout << "Son iguales" << endl;
        else cout << "No son iguales" << endl;
       }
    else cout << "No son iguales" << endl;
    return 0;
}
int strlen(char *word) // Recibe una cadena de caracteres.
{
    int count = 0; // Variable que que ira contando caracter por caracter.
    for (int i = 0;i < limit; i++) // La recorre hasta su limite.
    {
        if (int(word[i]) == 0) break; // Si se llega a un caracter nulo, quiere decir que en ese punto se acabo la cadena.
    count = count+1;
    }
return count; // Entrega la cantidad de caracteres que tiene dicha cadena.
}
bool same(char *word1, char *word2) // Recibe las dos cadenas de caracteres
{
int len = strlen(word1); // Las dos cadenas de caracteres cumplen con la condicion de tener la misma cantidad de caracteres.
for (int i=0;i<len;i++){
    if (word1[i] != word2[i]) return false; // Si alguno de sus caracteres en su misma posicion no son iguales, quiere decir que las cadenas son diferentes.
    }
return true; // Si todos sus caracteres son iguales, quiere decir que las dos cadenas son iguales.
}
