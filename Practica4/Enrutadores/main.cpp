
// Se cargan las librerias necesarias.

// Incluimos el objeto enrutador:
#include "enrutador.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

// Definimos un limite para los enrutadores.
#define limit 50

using namespace std;

typedef map<string, string> Dic_str; // Definimos una variable diccionario que en strings guarda strings.
typedef map<string, int> Dic_str_To_int; // Definimos una variable diccionario que en strings guarada enteros.
typedef list<enrutador> List_ruter; // Definimos una variable la cual es una lista de enrutadores

bool SearchDicc(string word, Dic_str_To_int dicc); // Busca una Key tipo string en una diccionario tipo Dic_str_To_int.
void Create_Table_cost_and_direction_ruter(enrutador *ruter, List_ruter ruters); // Crea a tabla de enrutamiento de un enrutador (con sus direcciones) y la guarada en el mismo.
void Conection_cost_ruters(enrutador *ruter1, enrutador *ruter2, int cost);// Define la conexcion entre dos enrutadores.
void Delete_cost_ruters(enrutador *ruter1, enrutador *ruter2); // Borra la conexcion entre dos enrutadores.

void imprimir(Dic_str_To_int dicc);
void imprimirS(Dic_str dicc);

int main(){

    enrutador enrutadres[limit];
    List_ruter list_ruter;

    char obtion;
    cout << "Bienvenido a la red de enrutadores" << endl;
    cout << endl;
    cout << "Tiene las siguientes obciones:" << endl;
    cout << endl;
    cout << "Cargar una red de enrutadores por defecto (A)" << endl;
    cout << endl;
    cout << "Cargar una red de enrutadores aleatorias (B)" << endl;
    cout << endl;
    cout << "Cual elige: ";
    cin >> obtion;

    if (obtion == char(65)){

        enrutadres[0].setName("ruterA");
        enrutadres[1].setName("ruterB");
        enrutadres[2].setName("ruterC");
        enrutadres[3].setName("ruterD");

        Conection_cost_ruters(&enrutadres[0], &enrutadres[1], 4);
        Conection_cost_ruters(&enrutadres[1], &enrutadres[3], 1);
        Conection_cost_ruters(&enrutadres[0], &enrutadres[2], 10);
        Conection_cost_ruters(&enrutadres[2], &enrutadres[3], 2);

        list_ruter.push_back(enrutadres[0]);
        list_ruter.push_back(enrutadres[1]);
        list_ruter.push_back(enrutadres[2]);
        list_ruter.push_back(enrutadres[3]);

    }
    else if (obtion == char(65)){

    }
    else{
     cout << "Error, obcion no definida" << endl;
    }

    Create_Table_cost_and_direction_ruter(&enrutadres[0], list_ruter);

    imprimir(enrutadres[0].getTable_cost_ruter());
    imprimirS(enrutadres[0].getTable_direction_ruter());

    return 0;
}

bool SearchDicc(string word, Dic_str_To_int dicc){
    Dic_str_To_int::iterator iter = dicc.find(word); // Buscamos la palabra word en el diccionario.
    if (iter != dicc.end()) return true;
    else return false;

}

void Conection_cost_ruters(enrutador *ruter1, enrutador *ruter2, int cost){
    // Hacemos copias de los enrutadores.
    enrutador enrutador1 = *ruter1;
    enrutador enrutador2 = *ruter2;
    // Guardamos los enrutadores con sus respectivos costos en cada enrutador.
    ruter1->setTable_cost(enrutador2, cost);
    ruter2->setTable_cost(enrutador1, cost);
}

void Delete_cost_ruters(enrutador *ruter1, enrutador *ruter2){
    // Hacemos copias de los enrutadores.
    enrutador enrutador1 = *ruter1;
    enrutador enrutador2 = *ruter2;
    // Eliminamos los enrutadores guaradados en cada enrutador.
    ruter1->Delete_setTable_cost(enrutador2);
    ruter2->Delete_setTable_cost(enrutador1);
}

void imprimir(Dic_str_To_int dicc){
    Dic_str_To_int::iterator iter = dicc.begin();
    while(iter != dicc.end()){
        cout << iter->first << "   " << iter->second << endl;
        iter++;
    }
}

void imprimirS(Dic_str dicc){
    Dic_str::iterator iter = dicc.begin();
    while(iter != dicc.end()){
        cout << iter->first << "   " << iter->second << endl;
        iter++;
    }
}

void Create_Table_cost_and_direction_ruter(enrutador *ruter, List_ruter ruters){
    // Aplicamos el algoritmo dijkstra.

    string less;
    enrutador ruter_copy;
    Dic_str_To_int Table_cost_operation;

    Dic_str Table_direction_ruter_official; // Guardamos las direcciones oficiales.
    Dic_str Table_direction_ruter_no_official; // Guardamos las posibles direcciones oficiales.

    Dic_str_To_int Table_cost_ruter_official; // Guardamos los costos oficiales de ir un enrutador a otro.
    Dic_str_To_int Table_cost_ruter_no_official; // Guardamos los posibles costos oficiales de ir un enrutador a otro.

    List_ruter::iterator Iter_ruters; // iterador para la lista de enrutadores.
    Dic_str_To_int::iterator Iter_Table_cost; // iterador para el diccionario tipo Dic_str_To_int.

    // Definimos cada variable deacuerdo al enrutador al que se le va a hacer la tabla de enrutamiento.

    Table_cost_ruter_no_official = ruter->getTable_cost();

    Table_cost_ruter_official[ruter->getName()] = 0;

    Table_direction_ruter_official[ruter->getName()] = "De "+ruter->getName()+" a "+ruter->getName();

    Iter_Table_cost = Table_cost_ruter_no_official.begin();

    while (Iter_Table_cost != Table_cost_ruter_no_official.end()){
        Table_direction_ruter_no_official[Iter_Table_cost->first] = "De "+ruter->getName()+" a "+Iter_Table_cost->first;
        Iter_Table_cost ++;
    }

    while(Table_cost_ruter_no_official.size() > 0){

        Iter_Table_cost = Table_cost_ruter_no_official.begin(); // Definimos al iterador desde el inicio del diccionario Table_cost_ruter_no_official,
        less = Iter_Table_cost->first;

        // Buscamos la Key del enrutador cuya costo de ida sea menor en el diccionario Table_cost_ruter_no_official.

        while (Iter_Table_cost != Table_cost_ruter_no_official.end()){
            if(Iter_Table_cost->second <= Table_cost_ruter_no_official[less]){
                less = Iter_Table_cost->first;
            }
            Iter_Table_cost ++;
        }

        Table_cost_ruter_official[less] = Table_cost_ruter_no_official[less]; // Lo grabamos en el diccionario oficial.
        Table_direction_ruter_official[less] = Table_direction_ruter_no_official[less]; // Lo eliminamos del diccionario no oficial.

        // Hacemos lo mismo con sus direcciones.

        Table_cost_ruter_no_official.erase(less);
        Table_direction_ruter_no_official.erase(less);

        Iter_ruters = ruters.begin(); // Definimos un iterador al inicio de la listade enrutadores.

        // Buscamos su respectivo enrutador en la lista de enrutadores.

        while(Iter_ruters != ruters.end()){
            ruter_copy = *Iter_ruters; // Hacemos una copia del enrutador.
            if (less == ruter_copy.getName()) break;
            Iter_ruters ++;
        }

        // Procedemos a grabar su Table_cost.

        Table_cost_operation = ruter_copy.getTable_cost();
        Iter_Table_cost = Table_cost_operation.begin();

        while(Iter_Table_cost != Table_cost_operation.end()) // Recoremos su Table_cost.
        {
            if(SearchDicc(Iter_Table_cost->first, Table_cost_ruter_official) == false) // Si no ha sido guardada en la oficial (La Key).
            {
                if(SearchDicc(Iter_Table_cost->first, Table_cost_ruter_no_official) == true) // Si esta en la no oficial.
                {
                    if ((Iter_Table_cost->second + Table_cost_ruter_official[less]) < Table_cost_ruter_no_official[Iter_Table_cost->first]) // Comparamos si el valor es menor que en el que esta en la no oficial (se le suma tambien su predecesor en el que se esta operando).
                    {
                        // Lo cambiamos el el caso de que lo sea, igual que con su direccion.
                        Table_cost_ruter_no_official[Iter_Table_cost->first] = Iter_Table_cost->second + Table_cost_ruter_official[less];
                        Table_direction_ruter_no_official[Iter_Table_cost->first] = Table_direction_ruter_official[less]+" a "+Iter_Table_cost->first;
                    }
                }
                else
                {
                    // Creamos una nueva Key en la no oficial con su valor correspondiente.
                    Table_cost_ruter_no_official[Iter_Table_cost->first] = Iter_Table_cost->second + Table_cost_ruter_official[less];
                    Table_direction_ruter_no_official[Iter_Table_cost->first] = Table_direction_ruter_official[less]+" a "+Iter_Table_cost->first;
                }
            }
            Iter_Table_cost ++;
        }

    }
    ruter->setTable_cost_ruter(Table_cost_ruter_official); // Guardamos la tabla de enrutamiento en el enrutador.
    ruter->setTable_direction_ruter(Table_direction_ruter_official); // Guardamos las direcciones de la tabla de enrutamiento.

}

