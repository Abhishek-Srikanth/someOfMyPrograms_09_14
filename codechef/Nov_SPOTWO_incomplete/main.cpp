#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void binary(int N, unsigned long long int &P)
{
    int c = 0;

    unsigned long long *pow = new unsigned long long int(0);
    while(N>0)
    {
        c++;
        *pow = (*pow)*10 + (N%2);
        N/=2;
    }
    while(c>0)
    {
        P = P*10 + (*pow)%10;
        (*pow)/=10;
        --c;
    }
    delete pow;
}

void _2nd_power(unsigned long long int &pw)
{
    unsigned long long int x = 1;
    while(pw > 0)
    {
        x*=4;
        while(x > 1000000007)
        {
            x%=   1000000007;
        }
        pw-=2;
    }
    cout << "x : " << x << endl;
}

int main()
{
    int N;
    cin >> N;
    unsigned long long int pw=0;
    binary(N, pw);
    pw *= 2;
    cout << "power is " << pw << endl;
    _2nd_power(pw);

    return 0;
}
