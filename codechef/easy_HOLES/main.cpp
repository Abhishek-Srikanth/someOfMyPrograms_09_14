#include <iostream>

using namespace std;

void func(short c = 0)
{
    char ch = NULL;
    cin >> ch;
    //cout << "ch IS " << ch << endl;
    do
    {
        if(ch=='B')
            {c+=2;}
        if(ch=='A' || ch=='D' || ch=='O' || ch=='P' || ch=='Q' || ch=='R')
            c++;
        if(ch=='\n')
            break;
        if(ch=='\r')
            break;
        cin.get(ch);
    }while(1);
    cout << c << endl;
}

int main()
{
    int T = 0;
    cin>> T;
    while(T--)
    {
        func();
    }
    return 0;
}
