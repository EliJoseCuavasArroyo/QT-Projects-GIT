#include <iostream>

using namespace std;
#define limit 50

int strlen(char*);

bool found(char*, char);

int main()

{
    char str[limit];
    char strcopy[limit] = "";
    cout << "Ingrese una cadena de caracteres: ";
    cin >> str;
    int len = strlen(str);
    int count = 0;
    for (int i=0;i<len;i++)
    {
        if (found(strcopy, str[i]) == false)
        {
            strcopy[count] = str[i];
            count = count+1;
            cout << str[i];
        }
    }
    cout << endl;
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
bool found(char *words, char term)
{
    int len = strlen(words);
    for (int i=0;i<len;i++){
        if (int(term) == int(words[i])) return true;
    }
    return false;
}
