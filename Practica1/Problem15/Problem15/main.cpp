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
    int matrix[n][n];
    int x=(0),y=(n-1), r=(n*n), actualy=(n), actualx =(0);
    while (r > 0){
    for (int i=y;i>=x;i--){
        matrix[x][i] = r;
        r--;
        actualy--;
        if (r < 0) break;
    }
    for (int i=(x+1);i<=y;i++){
        matrix[i][actualy] = r;
        r--;
        actualx++;
        if (r < 0) break;
    }
    for (int i=(actualy+1);i<y;i++){
        matrix[actualx][i] = r;
        r--;
        if (r < 0) break;
    }
    for (int i=actualx;i>(x);i--){
        matrix[i][y] = r;
        r--;
        if (r < 0) break;
    }
    y--;
    x++;
    actualy = y+1;
    actualx = x;
}
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (((matrix[i][j])/10) == 0) cout << matrix[i][j] << "   ";
            else cout << matrix[i][j] << "  ";
        }
    cout << endl;
    }
}
