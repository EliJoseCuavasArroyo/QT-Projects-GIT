#include <iostream>


using namespace std;

/* rand example: guess the number */

#include <stdio.h>
/* printf, scanf, puts, NULL */

#include <stdlib.h>
/* srand, rand */

#include <time.h>
/* time */


int main()
{

srand (time(NULL));

int num;
unsigned short int numguess;
unsigned short int limitmenor = 0;
unsigned short int limitmayor = 100;
char obtion = 88;
numguess = rand() % (limitmayor-limitmenor+1) + limitmenor;
cout << "Ingrese el numero que el programa tiene que adivinar: ";
cin >> num;

if ((num >= 0)&&(num <= 100)){

while (2>1)
    {
    cout << numguess << endl;
    cout << "Ingrese uno de los simbolos '>', '<' o '=', para definir la situacion de la cercania del numero presentado al numero que se desea adivinar: ";
    cin >> obtion;
    if (obtion == 62) limitmayor = numguess-1;
    else if (obtion == 60) limitmenor = numguess+1;
    else if (obtion == 61) break;
    else cout << "Obcion invalida, intente de nuevo" << endl;
    numguess = rand() % (limitmayor-limitmenor+1) + limitmenor;
    }

}

else
    {
    cout << "Error" << endl;
    }
return 0;
}

