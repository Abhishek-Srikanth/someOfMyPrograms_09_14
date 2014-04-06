#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    cout << "Please enter text below, # to terminate : " << endl;
    ofstream out ("file1.txt");
    char ch;
    for(;ch!='#';)
    {
        ch = getch();
        if(ch == '\n' || ch == '\r')
        {
            out << endl;
            cout << endl;
        }
        if(ch!='#')
        {
            cout << ch;
            out << ch;
        }
    }


    return 0;
}
