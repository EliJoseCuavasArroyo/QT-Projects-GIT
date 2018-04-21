#include <fstream>
#include <iostream>
#include <exception>

#define limit 50 // Establecemos un limite para el ingreso de una cadena de caracteres.

using namespace std;

int strlen(char*); // Esta funcion se encarga de entregar la cantidad de palabras que tiene un caracter.

void BinaryChange(char*, int); // Esta funcion convierte un entero en una cadena de caracteres la cual guarda su numero binario.

int getZeros(char*, int); // Esta funcion entrega la cantidad de ceros que tiene la cadena

void Codificacion1(ifstream* lectura, ofstream* escritura){
    cout << "Metodo 1 escogido" << endl;

    int n;
    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

        lectura->seekg(0, ios::end);
        int fin = lectura->tellg() - 1;

        lectura->seekg(0, ios::beg);
        char bloqueActual[100], bloquePasado[100], bloqueConvertido[100];

        int count = 0;
        int indice = 0;

        while(!lectura->eof()){
            lectura->read(bloqueActual,n);

            for(int i=0;i<n;i++){
                bloqueConvertido[i]=bloqueActual[i];
            }

            if(indice>=fin){
                break;
            }

            if(count == 0){
                for(int i=0;i<n;i++){
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            }
            else {
                int numZeros = getZeros(bloquePasado,n);
                cout << numZeros<<endl;

                if (n-numZeros==numZeros){ //Iguales
                    for(int i=0;i<n;i++){
                        if(bloqueActual[i]-48==0){
                            bloqueConvertido[i]=49;
                        }
                        else {
                            bloqueConvertido[i]=48;
                        }
                    }
                }
                else if(n-numZeros>numZeros){ //Hay mas 1
                    for(int i=2;i<n;i=i+3){
                        cout << int(bloqueActual[i]);
                        if(bloqueActual[i]-48==0){
                            bloqueConvertido[i]=49;
                        }
                        else {
                            bloqueConvertido[i]=48;
                        }
                    }
                } else { //Hay menos 1
                    for(int i=1;i<n;i=i+2){
                        if(bloqueActual[i]-48==0){
                            bloqueConvertido[i]=49;
                        }
                        else {
                            bloqueConvertido[i]=48;
                        }
                    }
                }
            }

            cout << "Actual: " << bloqueActual << endl;
            cout << "Convertido: " << bloqueConvertido << endl;
            int petro=909;
            if(lectura->eof() && indice<fin){
                petro = n - indice;
                escritura->write(bloqueConvertido,n-indice);
            }
            else {
                escritura->write(bloqueConvertido,n);
            }


            for(int i=0;i<n;i++){
                bloquePasado[i] = bloqueActual[i];
            }

            count++;
            indice = indice + n;
        }
}

void Codificacion2(ifstream* Read, ofstream* Write){
     cout << "Metodo 2 escogido" << endl;

     int n;
     cout << "Ingrese tamaño del bloque:" << endl;
     cin >> n;

}

int main(){

    char word = 0;
    char wordBinary[8];
    string File;
    cout << "Ingrese la ruta del mensaje a codificar:" << endl;
    cin >> File;

    // Abrimos el archivo de texto que procedemos a codificar.

    ifstream ReadWords;
    ReadWords.open(File);

    if(ReadWords.fail()){
        cout << "Error al abrir el archivo de lectura de las palabras" << endl;
        return -1;
    }

    // Creamos un archivo equivalente al que procedemos a codificar pero en codigo binario

    ofstream FileCopyBinary;
    FileCopyBinary.open("CopyFile.txt");

    if(FileCopyBinary.fail()){
        cout << "Error al abrir el archivo de lectura de las palabras en binario" << endl;
        return -1;
    }
    // Pasamos el archivo de texto a binario

    while(ReadWords.get(word))
    {
        BinaryChange(wordBinary, int(word));
        FileCopyBinary.write(wordBinary, 8);
    }

    // Cerramos los archivos

    ReadWords.close();
    FileCopyBinary.close();

    // Abrimos el archivo de texto en binario

    ifstream ReadBinaries;
    ReadBinaries.open("CopyFile.txt");

    if(ReadBinaries.fail()){
        cout << "Error al abrir el archivo de lectura binaria" << endl;
        return -1;
    }

    // Abrimos el archivo de texto que sera el de texto binario codificado

    string FileEncoded;
    cout << "Ingrese la ruta de salida: " << endl;
    cin >> FileEncoded;

    ofstream NewFileEncoded;
    NewFileEncoded.open(FileEncoded);

    if(NewFileEncoded.fail()){
        cout << "Error al abrir el archivo de texto binario codificado" << endl;
        return -1;
    }

    // Pedimos el metodo de codificacion

    int Metodo;
    cout << "Ingrese método de codificacion:" << endl;
    cin >> Metodo;

    switch (Metodo) {
    case 1:
        Codificacion1(&ReadBinaries, &NewFileEncoded);
        break;
    case 2:
        Codificacion2(&ReadBinaries, &NewFileEncoded);
        break;
    default:
        cout << "Método incorrecto" << endl;
        return -1;
    }

    // Cerramos los archivos

    ReadBinaries.close();
    NewFileEncoded.close();
    return 0;
}





int strlen(char *word) // Recibe una cadena de caracteres.
{
    int count = 0; // Variable que que ira contando caracter por caracter.
    for (int i = 0;i < limit; i++) // La recorre hasta su limite.
    {
        if (int(word[i]) == 0) break; // Si se llega a un caracter nulo, quiere decir que en ese punto se acabo la cadena.
    count = count+1;
    }
return count; // Entrega la cantidad de caracteres que tiene dicha cadena.
}

void BinaryChange(char* binary, int str){
    int binario[8] = {0,0,0,0,0,0,0,0};
    for (int i=7;i>=0;i--){
        if (str/2 == 0){
            binario[i] = str%2;
            break;
        }
        binario[i] = str%2;
        str = str/2;
    }
    for(int i=0;i<8;i++){
        binary[i] = 48+binario[i];
    }
}
int getZeros(char* str,int length){
    int count= 0;
    for(int i=0;i<length;i++){
        if(str[i]-48==0){
            count++;
        }
    }
    return count;
}
/*

void Codificacion1(ifstream* lectura,ofstream* escritura){
    cout << "Codicacion 1 escogida" << endl;

    int n;
    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

    lectura->seekg(0, ios::end);
    int fin = lectura->tellg() - 1;

    lectura->seekg(0, ios::beg);
    char bloqueActual[100], bloquePasado[100], bloqueConvertido[100];

    int count = 0;
    int indice = 0;

    while(!lectura->eof()){
        lectura->read(bloqueActual,n);

        for(int i=0;i<n;i++){
            bloqueConvertido[i]=bloqueActual[i];
        }

        if(indice>=fin){
            break;
        }

        if(count == 0){
            for(int i=0;i<n;i++){
                if(bloqueActual[i]-48==0){
                    bloqueConvertido[i]=49;
                }
                else {
                    bloqueConvertido[i]=48;
                }
            }
        }
        else {
            int numZeros = getCount(bloquePasado,n);
            cout << numZeros<<endl;

            if (n-numZeros==numZeros){ //Iguales
                for(int i=0;i<n;i++){
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            }
            else if(n-numZeros>numZeros){ //Hay mas 1
                for(int i=2;i<n;i=i+3){
                    cout << int(bloqueActual[i]);
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            } else { //Hay menos 1
                for(int i=1;i<n;i=i+2){
                    if(bloqueActual[i]-48==0){
                        bloqueConvertido[i]=49;
                    }
                    else {
                        bloqueConvertido[i]=48;
                    }
                }
            }
        }

        cout << "Actual: " << bloqueActual << endl;
        cout << "Convertido: " << bloqueConvertido << endl;
        int petro=909;
        if(lectura->eof() && indice<fin){
            petro = n - indice;
            escritura->write(bloqueConvertido,n-indice);
        }
        else {
            escritura->write(bloqueConvertido,n);
        }


        for(int i=0;i<n;i++){
            bloquePasado[i] = bloqueActual[i];
        }

        count++;
        indice = indice + n;
    }
}

void Codificacion2(ifstream* lectura,ofstream* escritura){
    cout << "Codicacion 2 escogida" << endl;

    int n;
    cout << "Ingrese tamaño del bloque:" << endl;
    cin >> n;

    lectura->seekg(0, ios::end);
    int fin = lectura->tellg() - 1;

    lectura->seekg(0, ios::beg);
    char bloqueActual[100], bloquePasado[100], bloqueConvertido[100];

    int count = 0;
    int indice = 0;

    while(!lectura->eof()){
        lectura->read(bloqueActual,n);

        if(indice>=fin){
            break;
        }

        if(lectura->eof() && indice<fin){
            bloqueConvertido[0]=bloqueActual[fin-indice-1];
            for(int i=1;i<fin-indice;i++){
              bloqueConvertido[i]=bloqueActual[i-1];
            }
            escritura->write(bloqueConvertido,fin-indice);
        }
        else {
            bloqueConvertido[0]=bloqueActual[n-1];
            for(int i=1;i<n;i++){
              bloqueConvertido[i]=bloqueActual[i-1];
            }
            escritura->write(bloqueConvertido,n);
        }

        cout << "Actual: " << bloqueActual << endl;
        cout << "Convertido: " << bloqueConvertido << endl;

        for(int i=0;i<n;i++){
            bloquePasado[i] = bloqueActual[i];
        }

        count++;
        indice = indice + n;
    }
}

*/
