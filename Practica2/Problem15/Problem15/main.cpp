#include <iostream>

using namespace std;
bool search(int*, int, int);

// Las siguientes funciones alteraran la variable donde se guardan los datos de la interseccion.

void basicinterseccion1(int*, int*, int*, int, int);
void basicinterseccion2(int*, int*, int*, int, int);
void basicinterseccion3(int*, int*, int*, int, int);
void basicinterseccion4(int*, int*, int*, int, int);

// La siguente funcion muestra la interseccion si es que existe.

void see(int*);

int main()
{
    // Inicializamos los arreglos donde guardaremos los datos de los dos cuadrados.

    int cuadrado1[4]; // Cuadrado 1.
    int cuadrado1copy[4]; // Copia del cuadrado 1
    int cuadrado2[4]; // Cuadrado 2.
    int interseccion[4]; // Variable donde guardaremos los datos de la interseccion.
    bool imaginebreaker = false; // Condicion para el ciclo de intersecciones basicas.
    bool condition = false; // Condicion para cambiar los cuadrados, si que uno se intersecta pero el otro no.
    bool failed; // Variable donde guardamos si la interseccion basica fallo.

    // Datos del cuadrado 1.

    cout << "Ingrese la coordenada x del primer cuadrado: ";
    cin >> cuadrado1[0];
    cout << "Ingrese la coordenada y del primer cuadrado: ";
    cin >> cuadrado1[1];
    cout << "Ingrese el ancho del primer cuadrado: ";
    cin >> cuadrado1[2];
    cout << "Ingrese el alto del primer cuadrado: ";
    cin >> cuadrado1[3];

    // Datos del cuadrado 2.

    cout << "Ingrese la coordenada x del segundo cuadrado: ";
    cin >> cuadrado2[0];
    cout << "Ingrese la coordenada y del segundo cuadrado: ";
    cin >> cuadrado2[1];
    cout << "Ingrese el ancho del segundo cuadrado: ";
    cin >> cuadrado2[2];
    cout << "Ingrese el alto del segundo cuadrado: ";
    cin >> cuadrado2[3];

    // Copiamos el cuadrado 1

    cuadrado1copy[0] = cuadrado1[0];
    cuadrado1copy[1] = cuadrado1[1];
    cuadrado1copy[2] = cuadrado1[2];
    cuadrado1copy[3] = cuadrado1[3];

    // Tenemos 4 tipos de intersecciones basicas.
    // 1. La parte superior izquierda esta en el otro cuadrado.
    // 2. La parte superior derecha esta en el otro cuadrado.
    // 3. La parte inferior izquierda esta en el otro cuadrado.
    // 4. La parte inferior derecha esta en el otro cuadrado.

    while (2>1){

        if (condition == true){

            imaginebreaker = true; // Romperemos el ciclo si la enterseccion basica no funciona

            // Intercambiamos los cuadrados

            cuadrado1[0] = cuadrado2[0];
            cuadrado1[1] = cuadrado2[1];
            cuadrado1[2] = cuadrado2[2];
            cuadrado1[3] = cuadrado2[3];

            cuadrado2[0] = cuadrado1copy[0];
            cuadrado2[1] = cuadrado1copy[1];
            cuadrado2[2] = cuadrado1copy[2];
            cuadrado2[3] = cuadrado1copy[3];

        }

        if (search(cuadrado1,cuadrado2[0],cuadrado2[1]) == true) //#1
        {
            basicinterseccion1(interseccion, cuadrado1, cuadrado2, cuadrado2[0], cuadrado2[1]);
            failed = false; // Funciono la interseccion basica.
            break;
        }
        else if (search(cuadrado1,(cuadrado2[0]+cuadrado2[2]),cuadrado2[1]) == true) //#2
        {
            basicinterseccion2(interseccion, cuadrado1, cuadrado2, (cuadrado2[0]+cuadrado2[2]), cuadrado2[1]);
            failed = false; // Funciono la interseccion basica.
            break;
        }
        else if (search(cuadrado1,cuadrado2[0],(cuadrado2[1]-cuadrado2[3])) == true) //#3
        {
            basicinterseccion3(interseccion, cuadrado1, cuadrado2, cuadrado2[0], (cuadrado2[1]-cuadrado2[3]));
            failed = false; // Funciono la interseccion basica.
            break;
        }
        else if (search(cuadrado1,(cuadrado2[0]+cuadrado2[2]),(cuadrado2[1]-cuadrado2[3])) == true) //#4
        {
            basicinterseccion4(interseccion, cuadrado1, cuadrado2, (cuadrado2[0]+cuadrado2[2]), (cuadrado2[1]-cuadrado2[3]));
            failed = false; // Funciono la interseccion basica.
            break;
        }
        else
        {
            condition = true; // Cambiemos los cuadrados.
        }

        if (imaginebreaker == true){
            failed = true; // No funciono la interseccion basica
            break; // Terminamos el ciclo en el caso de que interseccion basica no funciona.
        }
    }


    if (failed == true) // Si la interseccion basica fallo, procedemos a ver si existe na interseccion sintetica.
    {
        if (cuadrado1[1] > cuadrado2[1]){
            for (int i = 0; i<cuadrado1[3]; i++){
                if (search(cuadrado2, cuadrado1[0], (cuadrado1[1]-i)) == true) // Existe una division sintetica
                {
                basicinterseccion1(interseccion, cuadrado1, cuadrado2, cuadrado1[0], (cuadrado1[1]-i)); // Entonces al punto sintetico le hacemos una interseccion basica.
                see(interseccion); // Mostramos la interseccion.
                failed = false; // Funciono la interseccion sintetica.
                break;
                }
            }
        }
        else{
            for (int i = 0; i<cuadrado2[3]; i++){
                if (search(cuadrado1, cuadrado2[0], (cuadrado2[1]-i)) == true) // Existe una division sintetica
                    {
                    basicinterseccion1(interseccion, cuadrado1, cuadrado2, cuadrado2[0], (cuadrado2[1]-i)); // Entonces al punto sintetico le hacemos una interseccion basica.
                    see(interseccion); // Mostramos la interseccion.
                    failed = false; // Funciono la interseccion sintetica.
                    break;
                    }
                }

            }
    }
    else
    {
        see(interseccion); // Mostramos la interseccion, ya que si existio.
    }

    if (failed == true) cout << "No hay interseccion" << endl;

return 0;

}
void see(int *interseccion){

    cout << "(";
    for(int i=0;i<3;i++){
        cout << interseccion[i] << ", ";
    }
    cout << interseccion[3] << ")" << endl;

}
bool search(int *cuadrado, int pointx, int pointy){
    for(int i=0;i<=cuadrado[3];i++) // Recorremos a lo largo.
    {
        for(int j=0;j<=cuadrado[2];j++) // Recorremos a lo ancho.
        {
            if ((pointx == (cuadrado[0]+j)) && (pointy == (cuadrado[1]-i))) return true; // Si existe el punto es verdadero.
        }
    }
    return false;
}

void basicinterseccion1(int *interseccion, int *cuadrado1, int *cuadrado2, int pointx, int pointy){
    int width = 0;
    int longer = 0;
    while(((pointx+width) < (cuadrado1[0]+cuadrado1[2]))&&((pointx+width) < (cuadrado2[0]+cuadrado2[2]))){
        width = width+1;
    }
    while(((pointy-longer) > (cuadrado1[1]-cuadrado1[3]))&&((pointy-longer) > (cuadrado2[1]-cuadrado2[3]))){
        longer = longer+1;
    }
    interseccion[0]=pointx;
    interseccion[1]=pointy;
    interseccion[2]=width;
    interseccion[3]=longer;
}

void basicinterseccion2(int *interseccion, int *cuadrado1, int*cuadrado2, int pointx, int pointy){
    int width = 0;
    int longer = 0;
    while(((pointx-width) > cuadrado1[0])&&((pointx-width) > cuadrado2[0])){
        width = width+1;
    }
    while(((pointy-longer) > (cuadrado1[1]-cuadrado1[3]))&&((pointy-longer) > (cuadrado2[1]-cuadrado2[3]))){
        longer = longer+1;
    }
    interseccion[0]=pointx-width;
    interseccion[1]=pointy;
    interseccion[2]=width;
    interseccion[3]=longer;
}

void basicinterseccion3(int *interseccion, int *cuadrado1, int*cuadrado2, int pointx, int pointy){
    int width = 0;
    int longer = 0;
    while(((pointx+width) < (cuadrado1[0]+cuadrado1[2]))&&((pointx+width) < (cuadrado2[0]+cuadrado2[2]))){
        width = width+1;
    }
    while(((pointy+longer) < cuadrado1[1])&&((pointy+longer) < cuadrado2[1])){
        longer = longer+1;
    }
    interseccion[0]=pointx;
    interseccion[1]=pointy+longer;
    interseccion[2]=width;
    interseccion[3]=longer;
}

void basicinterseccion4(int *interseccion, int *cuadrado1, int*cuadrado2, int pointx, int pointy){
    int width = 0;
    int longer = 0;
    while(((pointx-width) > cuadrado1[0])&&((pointx-width) > cuadrado2[0])){
        width = width+1;
    }
    while(((pointy+longer) < cuadrado1[1])&&((pointy+longer) < cuadrado2[1])){
        longer = longer+1;
    }
    interseccion[0]=pointx-width;
    interseccion[1]=pointy+longer;
    interseccion[2]=width;
    interseccion[3]=longer;
}
