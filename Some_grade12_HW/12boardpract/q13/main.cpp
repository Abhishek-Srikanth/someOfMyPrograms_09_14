#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("memo.txt", ios::in);
    int v=0, s=0, c=0;
    char ch;
    while(in.eof()==0)
    {
        in.get(ch);
        if(ch == ' ')
            s++;
        else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            v++;
        c++;
    }
    cout << "v : " << v << " s: " << s << " c: " << c;
    return 0;
}
