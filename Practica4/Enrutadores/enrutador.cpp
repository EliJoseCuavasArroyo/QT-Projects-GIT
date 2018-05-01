
// Se caragan las librerias necesarias.

// Incluimos al objeto enrutador:
#include "enrutador.h"
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

typedef map<string, string> Dic_str; // Definimos una variable diccionario que en strings guarda strings.
typedef map<string, int> Dic_str_To_int; // Definimos una variable diccionario que en strings guarada enteros.

// Definimos las funciones del enrutador.

void enrutador::setName(string value)
{
    this->name = value;
}
void enrutador::setTable_cost(enrutador ruter, int cost)
{
    this->Table_cost[ruter.getName()] = cost;
}
void enrutador::Delete_setTable_cost(enrutador ruter)
{
    this->Table_cost.erase(ruter.getName());
}
void enrutador::setTable_cost_ruter(Dic_str_To_int dicc)
{
    this->Table_cost_ruter = dicc;
}
void enrutador::setTable_direction_ruter(Dic_str dicc1)
{
    this->Table_direction_ruter = dicc1;
}


Dic_str_To_int enrutador::getTable_cost()
{
    return Table_cost;
}
Dic_str_To_int enrutador::getTable_cost_ruter()
{
    return Table_cost_ruter;
}
Dic_str enrutador::getTable_direction_ruter()
{
    return Table_direction_ruter;
}
string enrutador::getName()
{
    return name;
}
