#include <iostream>

using namespace std;

long collatz(long long n, long depth)
{
    if(n==1)
        return depth;
    return (n%2==0)?(collatz(n/2, depth+1)):(collatz(3*n+1,depth+1));
}

int main()
{
    long long MAX = 0, val = 0, str = 0;
    for(long long i = 1; i < 1000000; ++i)
    {
        val = collatz(i, 1);
        cout << i << " -> " << val << endl;
        if(val > MAX)
        {
            MAX = val;
            str = i;
        }
    }
    cout << "MAX is : " << MAX << "and starting is " << str << endl;
    return 0;
}
