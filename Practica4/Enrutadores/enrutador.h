#ifndef ENRUTADOR_H
#define ENRUTADOR_H

// Cargamos las librerias necesarias.

#include <iostream>
#include <string> // Strings.
#include <map> // Diccionarios.
#include <list> // Listas.

using namespace std;

typedef map<string, string> Dic_str; // Definimos una variable diccionario que en strings guarda strings.
typedef map<string, int> Dic_str_To_int; // Definimos una variable diccionario que en strings guarada enteros.

class enrutador {
   private:

        string name; // Nombre del enrutador.
        Dic_str_To_int Table_cost; // Guardamos los valores que cuesta de ir de un enrutador a otro, en un diccionario el cual tiene como keys los nombres del enrutador.
        Dic_str_To_int Table_cost_ruter; // Guardamos su tabla de enrutamiento (costos).
        Dic_str Table_direction_ruter; // Guardamos las direcciones de la tabla de enrutamiento.

   public:

        // Prototipo de las funciones.

        void setName(string value); // Consige el nombre.
        void setTable_cost(enrutador ruter, int cost); // Guarda el nombre de un enrutador y el costo de llegar al enrutador.
        void Delete_setTable_cost(enrutador ruter); // Borra la clave del enrutador.
        void setTable_cost_ruter(Dic_str_To_int dicc); // Recibe la tabla de enrutamiento.
        void setTable_direction_ruter(Dic_str dicc1); // Recibe la tabla de direcciones.

        // Las funciones get entregan sus respectivas variables.

        string getName();
        Dic_str_To_int getTable_cost();
        Dic_str_To_int getTable_cost_ruter();
        Dic_str getTable_direction_ruter();

};

#endif // ENRUTADOR_H
