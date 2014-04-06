#include <iostream>

using namespace std;

int main()
{
    double a=56.77;

    while (a<=60)
    {
        cout << a << endl;
        a+=0.01;
    }
    cout << "all finished!!!!!\n\n" << endl;

    int b=-7;

    do
    {
        cout << b << endl;
        b+=3;
    }
    while (b<=5);

    int z;
    for ( z=0; z<10; z++)
    {
        cout << z << " ";

        if (z==4)
        {
            break;
        }
    }

    cout << "\n\nall finished!!!" << endl;


    int x;
    for (x=0; x<=10; x++)
    {
        cout << x << " ";
        if (x==8)
        {
            cout << endl;
            continue;
        }
        cout << x*2 << endl;
    }
    cout << " \n\n\nnow i am really done!!!" << endl;


    return 0;
}
