#include <iostream>

using namespace std;

void matriz(int);// Funcion que imprime la matriz nxn.
int main()
/* El programa recibe un numero positivo y entero.
 * El programa entrega la suma de los numeros en la diagonal de la matriz nxn espiral.
 */
{
    int range, sum=1, criterion=0, num=1;
        /*
         -En la variable sum, mantendremos la suma de los números de la matriz diagonal.
         -La variable criterion es el criterio de aumento por el cual tomará cada número.
         -La variable num son los números que cumplen el criterio de aumento y deben agregarse.
        */
    cout << "Ingrese un numero impar positivo, el cual sea el rango de la matriz par: ";
    cin >> range; // Capturamos el numero del rango de la matiz nxn.
    while (num<(range*range)) // Mientras los numero que cumplan el criterio de aumento sean menores al numero maximo.
    {
        criterion = criterion+2; // El criterio de incremento, aumenta de 2 en 2.
        for (int i =0;i<4;i++) //Se toman los siguientes 4 números que cumplen con el criterio de aumento.
        {
            num = num+criterion; // Cada numero debe tener una diferencia del criterio de incremento.
            sum = sum+num; // Acumulamos el numero en la variable sum.
        }
    }
    cout << endl;
    matriz(range); // Mostramos la matriz en la terminal.
    cout << endl;
    cout << "La suma de los numeros en la diagonal de la matriz es: " << sum << endl;
    return 0;
}
void matriz(int n){
    int matrix[n][n]; // Inicializamos una matriz nxn cualquiera.
    int x=(0),y=(n-1), r=(n*n), actualy=(n), actualx =(0);
    // La variable r, representa el maximo numero de la matriz.
    // La variable x, representa las filas.
    // La variable y, representa las columnas.
    // Mientras nos movamos poniendo los numeros, la variable actualx, representa la posicion de fila actual.
    // Mientras nos movamos poniendo los numeros, la variable actualy, representa la posicion de columna actual.
    // Partimos desde la posicion nxn, poniendo el maximo numero que es n*n, continuamente, por cada vez que avancemos una posicion, se ira disminuyendo de uno en uno el numero.
    while (r > 0){
    for (int i=y;i>=x;i--)
    // Primero, nos movemos desde la esquina superior derecha hacia la esquina superior izquierda.
    {
        matrix[x][i] = r;
        r--;
        actualy--;
        if (r < 0) break;
    }
    for (int i=(x+1);i<=y;i++)
    // Segundo, nos movemos desde la esquina superior izquierda hasta la esquina inferior izquierda.
    {
        matrix[i][actualy] = r;
        r--;
        actualx++;
        if (r < 0) break;
    }
    for (int i=(actualy+1);i<y;i++)
    // Tercero, nos movemos desde la esquina inferior izquierda hasta la esquina inferior derecha.
    {
        matrix[actualx][i] = r;
        r--;
        if (r < 0) break;
    }
    // Cuarto, nos movemos desde la esquina inferior izquierda, hasta la esquina superior derecha, sin tomar el espacio que fue tomado al inicio.
    for (int i=actualx;i>(x);i--){
        matrix[i][y] = r;
        r--;
        if (r < 0) break;
    }
    // Actualizamos la variable, para volver a realizar el proceso, pero con diferentes limites en las esquinas superiores e inferiores.
    y--;
    x++;
    actualy = y+1;
    actualx = x;
}
    // Imprimimos la matriz.
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (((matrix[i][j])/10) == 0) cout << matrix[i][j] << "   "; // En el caso de que sea un digito, dejamos tres espacios.
            else cout << matrix[i][j] << "  "; // En el caso de que sea dos digitos dejamos dos espacios.
        }
    cout << endl;
    }
}
