#include <iostream>

using namespace std;

bool isprime(long &k)
{
    if(k%2==0)
        return 0;
    for(long i = 3; i < k; i+=2)
    {
        if(k%i==0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    unsigned long long sum = 2;
    for(long i = 3; i < 2000000; ++i)
    {
        if(isprime(i)==1)
        {
            sum+=i;
            cout << i << endl;
        }

    }
    cout << endl << sum << endl;
    return 0;
}
