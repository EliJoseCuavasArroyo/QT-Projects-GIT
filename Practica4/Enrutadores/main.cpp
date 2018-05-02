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
typedef list<int> List_ruter_int;

bool SearchDicc(string word, Dic_str_To_int dicc); // Busca una Key tipo string en una diccionario tipo Dic_str_To_int.
void Create_Table_cost_and_direction_ruter(enrutador *ruter, List_ruter ruters); // Crea a tabla de enrutamiento de un enrutador (con sus direcciones) y la guarada en el mismo.
void Conection_cost_ruters(enrutador *ruter1, enrutador *ruter2, int cost);// Define la conexcion entre dos enrutadores.
void Delete_cost_ruters(enrutador *ruter1, enrutador *ruter2); // Borra la conexcion entre dos enrutadores.

void Print(Dic_str_To_int dicc);
void PrintS(Dic_str dicc);

int main(){

    int num;
    int cost;

    string word;
    enrutador ruter_copy;
    Dic_str_To_int  operation;

    enrutador enrutadres[limit];
    List_ruter list_ruter_in_use;
    List_ruter_int ruters_in_use;
    List_ruter_int ruters_aviable;

    List_ruter_int::iterator Iter_ruters; // iterador para la lista de enrutadores.
    Dic_str_To_int::iterator Iter_table_ruter; // iterador para el diccionario

    char obtion;
    cout << "Bienvenido a la red de enrutadores" << endl;
    cout << endl;
    cout << "Tiene las siguientes obciones:" << endl;
    cout << endl;
    cout << "Cargar una red de enrutadores por defecto (A)" << endl;
    cout << endl;
    cout << "Cargar una red de enrutadores de un archivo (B)" << endl;
    cout << endl;
    cout << "Cargar una red de enrutadores aleatorias (C)" << endl;
    cout << endl;
    cout << "Cual elige: ";
    cin >> obtion;

    while (2>1)
    {
        if (obtion == char(65)){

            enrutadres[0].setName("ruterA");
            enrutadres[1].setName("ruterB");
            enrutadres[2].setName("ruterC");
            enrutadres[3].setName("ruterD");

            Conection_cost_ruters(&enrutadres[0], &enrutadres[1], 4);
            Conection_cost_ruters(&enrutadres[1], &enrutadres[3], 1);
            Conection_cost_ruters(&enrutadres[0], &enrutadres[2], 10);
            Conection_cost_ruters(&enrutadres[2], &enrutadres[3], 2);

            list_ruter_in_use.push_back(enrutadres[0]);
            list_ruter_in_use.push_back(enrutadres[1]);
            list_ruter_in_use.push_back(enrutadres[2]);
            list_ruter_in_use.push_back(enrutadres[3]);

            for(int i=0;i<4;i++){
                ruters_in_use.push_back(i);
            }
            for(int i=4;i<51;i++){
                ruters_aviable.push_back(i);
            }

            break;
        }
        else if (obtion == char(66)){

        }
        else if (obtion == char(67)){

        }
        else{
         cout << "Error, obcion no definida" << endl;
        }

    }

    cout << endl;
    cout << "La red de enrutadores ya esta cargada" << endl;

    while (2>1)
    {
        cout << endl;
        cout << "Tiene las siguientes obciones:" << endl;
        cout << endl;
        cout << "Agregar enrutador (A)" << endl;
        cout << endl;
        cout << "Remover enrutador (B)" << endl;
        cout << endl;
        cout << "Desea saber cuanto cuesta enviar un paquete desde un enrutador origen a uno destino (Con su direccion incluida) (C)" << endl;
        cout << endl;
        cout << "Salir (D)" << endl;
        cout << endl;
        cout << "Cual elige: ";
        cin >> obtion;
        cout << endl;

        if (obtion == char(65)) // A
        {
            cout << "Ingrese el nombre del nuevo enrutador: ";
            cin.ignore();
            getline(cin, word);
            cout << endl;

            Iter_ruters = ruters_aviable.begin();
            num = *Iter_ruters;

            enrutadres[num].setName(word); // Le ponemos nombre.
            ruters_in_use.push_back(num); // Lo agragamos a la lista de los que estan en uso.
            Iter_ruters = ruters_aviable.erase(Iter_ruters); // Borramos de las lista de los disponibles, ya que no esta disponible.

            while (2>1){
                cout << "Desea hacer una conexcion (S/N): ";
                cin >> obtion;
                if (obtion == char(83)) // SI
                {
                    cout << "Ingrese el nombre del enrutador con el cual va a conectar: ";
                    cin.ignore();
                    getline(cin, word);
                    cout << word << endl;
                    Iter_ruters = ruters_in_use.begin();
                    while(Iter_ruters != ruters_in_use.end()){
                         if (word == enrutadres[*Iter_ruters].getName()) break;
                          Iter_ruters ++;
                    }
                    cout << "Ingrese el costo: ";
                    cin >> cost;
                    Conection_cost_ruters(&enrutadres[num], &enrutadres[*Iter_ruters], cost);
                }
                else if (obtion == char(78)) // NO
                {
                    break;
                }
                else
                {
                    cout << "Obcion no definida" << endl;
                }

            }

            // Actualizamos la lista de los enrutadores en uso.

            list_ruter_in_use.clear();
            Iter_ruters = ruters_in_use.begin();
            while(Iter_ruters != ruters_in_use.end()){
                list_ruter_in_use.push_back(enrutadres[*Iter_ruters]);
                Iter_ruters ++;
            }
        }
        else if (obtion == char(66)) // B
        {
            cout << "Ingrese el nombre del enrutador a remover: ";
            cin.ignore();
            getline(cin, word);
            cout << endl;

            Iter_ruters = ruters_in_use.begin(); // Buscamos el enrutador el cual aun debe estar en uso.
            while(Iter_ruters != ruters_in_use.end()){
                 if (word == enrutadres[*Iter_ruters].getName()) break;
                  Iter_ruters ++;
            }

            num = *Iter_ruters;
            Iter_ruters = ruters_in_use.erase(Iter_ruters); // Lo eliminamos de la lista de enrutadores que estan en uso.
            ruters_aviable.push_back(num); // Lo ponemos en la lista de los disponibles.

            operation = enrutadres[num].getTable_cost(); // Buscamos sus conexciones.
            Iter_table_ruter = operation.begin();

            while (Iter_table_ruter != operation.end()) {
                word = Iter_table_ruter->first; // Buscaremos atraves de su nombre.
                Iter_ruters = ruters_in_use.begin(); // Buscamos el enrutador para hacer la desconexcion.
                while(Iter_ruters != ruters_in_use.end()){
                     if (word == enrutadres[*Iter_ruters].getName()){
                         Delete_cost_ruters(&enrutadres[num], &enrutadres[*Iter_ruters]);
                         break;
                     }
                      Iter_ruters ++;
                }
                Iter_table_ruter ++;
            }

            // Actualizamos la lista de los enrutadores en uso.

            list_ruter_in_use.clear();
            Iter_ruters = ruters_in_use.begin();
            while(Iter_ruters != ruters_in_use.end()){
                list_ruter_in_use.push_back(enrutadres[*Iter_ruters]);
                Iter_ruters ++;
            }
        }
        else if (obtion == char(67)) // C
        {
            cout << "Ingrese el nombre del enrutador: ";
            cin.ignore();
            getline(cin, word);
            cout << endl;
            Iter_ruters = ruters_in_use.begin();
            while(Iter_ruters != ruters_in_use.end()){
                 if (word == enrutadres[*Iter_ruters].getName()) break;
                  Iter_ruters ++;
            }
            Create_Table_cost_and_direction_ruter(&enrutadres[*Iter_ruters], list_ruter_in_use);
            Print(enrutadres[*Iter_ruters].getTable_cost_ruter());
            cout << endl;
            PrintS(enrutadres[*Iter_ruters].getTable_direction_ruter());
        }
        else if (obtion == char(68)) // D
        {
            break;
        }
        else{
            cout << "Error, obcion no definida" << endl;
        }

    }
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

void Print(Dic_str_To_int dicc){
    Dic_str_To_int::iterator iter = dicc.begin();
    while(iter != dicc.end()){
        cout << iter->first << " :  " << iter->second << endl;
        iter++;
    }
}

void PrintS(Dic_str dicc){
    Dic_str::iterator iter = dicc.begin();
    while(iter != dicc.end()){
        cout << iter->first << " :  " << iter->second << endl;
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
        Table_direction_ruter_official[less] = Table_direction_ruter_no_official[less]; // Hacemos lo mismo con sus direcciones.

        // Lo eliminamos del diccionario no oficial.

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

