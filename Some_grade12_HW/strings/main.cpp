#include <iostream>
#include <string>

using namespace std;

int main()
{
    /**
    string str1 = "Hello World";
    cout << str1;
    cout << endl;
    cin >> str1;
    cout << str1 << endl;
    for(int i = 0; i < str1.length(); ++i)
    {
        cout << str1[i] << "\t";
    }
    string::const_iterator itr;
    for(itr = str1.begin(); itr!=str1.end(); ++itr)
    {
        cout << *itr << endl;
    }
    string str2 = "Srikanth";
    str1 += " " + str2;
    cout << endl << str1 << endl;

    */

    string bigstr = "Hello world, this is me, Abhishek wishing you good morning and a good day and suggest you start your good day with a cookie!";
    int pos = -1;
    top:
    pos = bigstr.find("good", pos+1);
    if(pos != string::npos)
    {
        cout << "Found good at -> " << pos << endl;
        goto top;
    }
    cout << "Time to remove a good : " << endl << bigstr << endl;
    size_t p1 = bigstr.find("good",0);
    string::iterator P = bigstr.begin();
    P+=p1;
    if(p1 != string::npos)
    {
        bigstr.erase(P, P+5);
    }
    cout << bigstr << endl;
    return 0;
}
