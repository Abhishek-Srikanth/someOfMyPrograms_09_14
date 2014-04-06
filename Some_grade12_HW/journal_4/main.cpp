#include <iostream>
#include <string.h>


using namespace std;

int pstrcmp(char *a, char *b)
{
    if(strlen(a)!= strlen(b))
    return -1;


    while(*a != '\0' && *b != '\0')
    {
        if(*a!=*b)
        return -2;
        a++;
        b++;
    }
    return 0;
}

int pl2u(char *a,int n)
{
    for(int i = 0; i < n; ++i)
    {
        if(*a >= 97 && *a <= 122)
        *a-=32;
        a++;
    }
    return 0;
}



int main()
{
    char a[] = {"My Name Will bE conVERTED to all zzzzaaaaaazzzz"};
    pl2u(a,strlen(a));
    cout << a;
    return 0;
}
