#include <iostream>

using namespace std;

int main()
{
    long long longest=354;
    long nlong = 106239;
    for(long i = 113382; i < 1000001; ++i)
    {
        long t = i;
        long long c=1;
        while(t!=1)
        {
            ( t%2==0 ) ? ( t/=2 ) : ( t= (3*t) +1 ) ;
            ++c;
            if(c%25000==0)cout << "\t";
            if(c>1000000)
            {
                cout << "\nTOO MUCH AT : " << i << endl;
                goto end;
            }
        }
        if(c>longest)
        {
            longest = c;
            nlong=i;
        }
        if(i%100==0)
            cout << i << " -> " << c << " and current longest is " << longest << " for nlong = " << nlong << endl;
        end:;

    }
    cout << "\n\nlongest chain is : " << longest << " and nlong is " << nlong << "\n";
    return 0;
}
