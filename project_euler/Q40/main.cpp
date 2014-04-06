#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string str = "0";
    for(int i = 1; str.length()<1000001; ++i)
    {
        ostringstream buffer;
        buffer << i;
        string p = buffer.str();
        str+=p;
    }
    cout << str;
    cout << endl << str[1] << "\n"
         << str[10] << endl
         << str[100] << endl
         << str[1000] << endl
         << str[10000] << endl
         << str[100000] << endl
         << str[1000000] << endl;
    return 0;
}
