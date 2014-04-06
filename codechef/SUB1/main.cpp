#include <iostream>

using namespace std;

int main()
{

    int T;
    cin >> T;
while(T>0)
{
    int N;
    cin >> N;
    unsigned long int a[N], s = 1000000000, val=0;
    for(int i = 0; i < N; ++i)
    {
        cin >> a[i];
        if(s > a[i])
            s = a[i];
    }
    abc:
    for(int i = 0; i < N; ++i)
    {
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
        cout << val << endl;
        goto end;
    }
    val = s;
    for(int i = 0; i < N; ++i)
    {
        if(a[i]<s)
            s = a[i];
    }

    if(val==s)
        cout << val << endl;
    else
        goto abc;
    end:
    --T;
}

return 0;}
