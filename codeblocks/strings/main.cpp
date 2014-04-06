#include <iostream>

using namespace std;

int main()
{
    string mystring;
    mystring = "sup";
    cout << mystring << endl;
    cout << mystring[0] << endl;
    mystring[2]='e';
    cout << mystring << endl;
    mystring += 'd';
    cout << mystring << endl;
    mystring += " you" ;
    cout << mystring << endl;
    string s2= "I ";
    cout << s2 << mystring << endl;
    string x = s2 + mystring + " too!!!!!";
    cout << x << endl;
    return 0;
}
