#include <iostream>

using namespace std;

int main()
{
    char fila;
    char reservation;
    int columna;
    bool seating[15][20];
    for (int i=0;i<15;i++){
        for (int j=0;j<20;j++){
        seating[i][j] = false;
        }
    }
    while (2>1)
    {
       cout << "Desea hacer una reservacion (S/N): ";
       cin >> reservation;
       if (reservation == 83){
           cout << "Ingrese la fila de A-O: ";
           cin >> fila;
           cout << "Ingrese el numero del asiento: ";
           cin >> columna;
           if ((fila>=65)&&(fila<=79)&&(columna>=1)&&(columna<=20)){
                seating[int(fila)-65][columna-1] = true;

                for (int i=0;i<15;i++){
                    for (int j=0;j<20;j++){
                        if (seating[i][j] == true) cout << "+ ";
                        else cout << "- ";
                        }
                    cout << endl;
                    }
                }
            else cout << "Asiento invalido" << endl;
       }
       else if (reservation == 78) break;
       else cout << "Esa opcion no esta definida" << endl;
    }
    return 0;
}
