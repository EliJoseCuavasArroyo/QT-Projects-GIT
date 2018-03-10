#include <iostream>

using namespace std;
#define limit 50

int strlen(char*);
bool same(char* ,char*);
int main()
{
    char str1[limit];
    char str2[limit];
    cout << "Ingrese el primer caracter: ";
    cin >> str1;
    cout << "Ingrese el segundo caracter: ";
    cin >> str2;
    if (strlen(str1) == strlen(str2)){
        if (same(str1, str2) == true) cout << "Son iguales" << endl;
        else cout << "No son iguales" << endl;
       }
    else cout << "No son iguales" << endl;
    return 0;
}
int strlen(char *word)
{
    int count = 0;
    for (int i = 0;i < limit; i++){
        if (int(word[i]) == 0) break;
    count = count+1;
    }
return count;
}
bool same(char *word1, char *word2)
{
int len = strlen(word1);
for (int i=0;i<len;i++){
    if (word1[i] != word2[i]) return false;
    }
return true;
}
