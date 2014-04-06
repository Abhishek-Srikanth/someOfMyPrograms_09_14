#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    ifstream in("poem.txt", ios::in);
    char word[10];
    char read[10];
    cout << "Enter word to read : ";
    cin >> word;
    int c = 0;
    while(in)
    {
        in >> read;
        if(read[strlen(read)-1]=='.' || read[strlen(read)-1]==',')
        {
            read[strlen(read)-1]='\0';
        }
        if(strcmpi(word,read)==0)
            c++;
    }
    cout << c;
    return 0;
}
