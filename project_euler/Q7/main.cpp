#include <iostream>

using namespace std;

int isprime(long &k)
{
    for(int i = 3; i < k; i+=2)
    {
        if(k%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int c=1;
    //long buffer=3;
    for(long i = 3; c!=10001; i+=2)
    {
        if( isprime(i) == 1)
        {
            ++c;
            //buffer = i;
            cout << "number " << c << " : " << i << endl;
        }
    }
    //cout << endl << endl << "value is " << buffer << endl;
    return 0;
}
