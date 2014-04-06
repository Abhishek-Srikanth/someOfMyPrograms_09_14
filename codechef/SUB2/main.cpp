#include <iostream>

using namespace std;


int func(unsigned long a[], int N)
{
    unsigned long int s = 1000000000, val=0;
    for(int i = 0; i < N; ++i)
    {
        if(s > a[i] && a[i]!=0)
            s = a[i];
    }
    abc:
    for(int i = 0; i < N; ++i)
    {
        if(a[i]==0)
            continue;
        a[i]=a[i]%s;
        if(a[i]==0)
        {
            a[i] = s;
        }
        if(a[i]==1)
            val = 1;
    }

    if(val==1)
    {
        return 1;
    }
    val = s;
    for(int i = 0; i < N; ++i)
    {
        if(a[i]<s && a[i]!=0)
            s = a[i];
    }

    if(val!=s)
        goto abc;
    return 0;
}


int main()
{
    int N;
    cin >> N;
    int c[N];
    unsigned long int a[N];
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
        c[i] = N;
    }
    int counter = 0;

    for(int i = 2; i < N; ++i)
    {
        unsigned long int d[i];
                for(int m=0; m<N; ++m)d[m]=0;

        for(int j = 0; j < i; ++j)
            c[j]=0;
        topo:
        for(int j=0; j < i; ++j)
        {
            d[j] = a[c[j]];
            cout << d[j] << "  ";
        }

        /**********/
        cout << endl;

        counter+=func(d,i);
        for(int k = N-1; k >= 0; --k)
        {
            if(c[k]!=(N))
            {
                c[k]++;
            }
   /**and**/if(c[k]==(N) || c[k]==(N+1))
            {
                c[k] = N;
                c[k-1]++;
            }
        }
        if(c[0]!=(N))
            goto topo;

    }

    cout << counter;

    return 0;
}
