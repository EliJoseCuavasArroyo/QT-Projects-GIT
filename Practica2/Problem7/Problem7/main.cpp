#include <iostream>

using namespace std;
#define limit 50 // Establecemos un limite para el ingreso de un caracter.

int strlen(char*); // Esta funcion se encarga de entregar la cantidad de palabras que tiene un caracter.

bool found(char*, char); // Esta funcion busca un caracter especifico en una cadena de caracteres.

// El programa recibe una cadena de caracteres y elimina los caracteres repetidos.

int main()

{
    char str[limit]; // Definimos la cadena de caracteres que ingresara en usuario.
    char strcopy[limit] = ""; // Definimos una cadena donde guardaremos caracter por caracter de la cadena anterior, en el caso de que este repetido, no los guardaremos.
    cout << "Ingrese una cadena de caracteres: ";
    cin >> str;
    int len = strlen(str); // Capturamos la cantidad de caracteres de la cadena ingresada por el usuario.
    int count = 0; // Esta varaible equivale a la posicion de los caracteres de la cadena de caracteres strcopy.
    for (int i=0;i<len;i++)
    {
        if (found(strcopy, str[i]) == false) // Si no esta en la cadena strcopy.
        {
            strcopy[count] = str[i]; // Actualizamos strcopy.
            count = count+1; // Seguimos con la siguiente posicion.
            cout << str[i]; // Lo imprimimos ya que no esta repetido hasta en momento
        }
    }
    cout << endl;
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
bool found(char *words, char term) // Recibe una cadena de caracteres, y un caracter especifico a buscar.
{
    int len = strlen(words); // Capturamos la cantidad de caracteres de la cadena de caracteres ingresada a la funcion
    for (int i=0;i<len;i++) // Recorremos la cadena de cadena de caracteres.
    {
        if (int(term) == int(words[i])) return true; // Si esta el caracter que estamos buscando, retornamos un true.
    }
    return false; // Si en toda la cadena no esta, entonces retornamos un false.
}
