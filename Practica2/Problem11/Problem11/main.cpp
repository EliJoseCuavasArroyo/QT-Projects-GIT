#include <iostream>

using namespace std;

int main()
{
    char fila; // Se guaradaran las filas de A-O.

    int columna; // Se guaradara el numero del asiento de 1-20.

    char reservation; // Se guardara las obciones de que si quiere hacer reservacion o no.

    bool seating[15][20]; // Creamos la matriz.

    for (int i=0;i<15;i++) // Como no se ha hecho reserva, hacemos que todos los asientos esten disponibles.
    {
        for (int j=0;j<20;j++){
        seating[i][j] = false;
        }
    }
    cout << "Actualmente todos los asientos estan disponibles para reserva." << endl;
    while (2>1)
    {
       cout << "Desea hacer una reservacion (S/N): ";
       cin >> reservation; // Capturamos la obcion del usuario.

       if (reservation == 83) // Si la obcion es el caracter S, quiere decir que quiere hacer una.
       {
           cout << "Ingrese la fila de A-O: ";
           cin >> fila;
           cout << "Ingrese el numero del asiento: ";
           cin >> columna;
           if ((fila>=65)&&(fila<=79)&&(columna>=1)&&(columna<=20)) // Si las varaibles filas y columnas estan dentro del rango, procedemos a realizar la reservacion.
                {
               if (seating[int(fila)-65][columna-1] != true) // Si no esta reservada.
               {
                seating[int(fila)-65][columna-1] = true; // Hacemos la reserva.
               }
               else
               {
                   cout << endl << "Ya esta reservada" << endl << endl;
               }
                // Mostramos la matriz.

                for (int i=0;i<15;i++){
                    for (int j=0;j<20;j++){
                        if (seating[i][j] == true) cout << "+ ";
                        else cout << "- ";
                        }
                    cout << endl;
                    }
                }
            else cout << "Asiento invalido" << endl; // En el caso de que el usuario ingrese un obcion no definida.
       }
       else if (reservation == 78) break; // Si la obcion es el caracter N, quiere decir que no quiere hacer una.
       else cout << "Esa opcion no esta definida" << endl;
    }
    return 0;
}
