#include <iostream>

using namespace std;

int nfactors(long long &num)
{
    int c = 0;
    for(int i = 1; i <= num; ++i)
    {
        if(num%i==0)
            c++;
    }
    return c;
}

int main()
{
    long long sum = 57464560;
    for(int i = 10721;; ++i)
    {
        sum+=i;
        // sum is a triangle number
        int nfac = nfactors(sum);
        cout << i << "th term -> " << sum << " : " << nfactors(sum) << endl;
        if(nfac>=500)
        {
            break;
        }
    }
    return 0;
}
