#include <iostream>

using namespace std;

int main()
{
    int x=0;
    int i;

    for ( i=1; i<=100; i+=1)
    {
        x+=i;
    }

    cout << x << endl;

    for ( i=10; i>+5; i--)
    {
        cout << i << endl;
    }

    cout << endl;

    for ( int a = 30; a<45; a++)
    {
        cout << a << endl;
    }

    double s;

    for (s=200; s<=202; s+=0.1)
    {
        cout << s << endl;
    }

    int q,w;
    for ( q = 0, w = 10; q<=5, w>=5; q++, w=w-1)
    {
        cout << q << "     " << w << endl;
    }

    return 0;

}
