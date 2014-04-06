#include <iostream>

using namespace std;

int main()
{
    long long a=1, b=1,sum = 0;
    while(a<=4000000 && b<=4000000)
    {
        long long n = a+b;
        (a<=b) ? a=n : b=n;
        if(n%2==0)
            sum+=n;
    }
    cout << sum;
    return 0;
}
