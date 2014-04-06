#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream read("C:\\Users\\Abhish\\Desktop\\Journal_4\\J4FQ1\\file1.txt");
    int nc=0,nw=0;
    while(!read.eof())
    {
        char ch;
        read >> ch;
        if(ch=='_')
        {
            nw++;
            cout << " ";
        }
        else
            cout << ch;
        nc++;
    }
    cout << endl;

    cout << "no of words : " << nw << endl;
    cout << "no of chars : " << nc << endl;

    return 0;
}
