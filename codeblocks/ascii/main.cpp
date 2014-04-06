#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int m=1;
    char x = 1;

    for (int i = 1; i<256; i++)
    {
        if (i!=26)
        {
            cout << "ASCII " << i << " is " << x << endl;
        }
        x++;
        if (m%20==0)
        system("PAUSE");
        m++;
    }
    system("PAUSE");
    return 0;
}
