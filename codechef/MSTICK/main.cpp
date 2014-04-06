#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    unsigned int L=0,R=0,N,Q;
    cin >> N;
    unsigned long /* long long */ a[N];
    for(L = 0; L < N; ++L)
    {
        cin >> a[L];
    }
    cin >> Q; // No of queries
    L=0;
    for(unsigned int i = 0; i < Q; ++i)
    {
        cin >> L >> R;
        unsigned long s = a[L];
        for(unsigned int j = L; j <= R; ++j)
            if(a[j]<s)
                s = a[j];

        // test statement //
        // cout << endl << endl << "s is : " << s << endl << "L,R is : " << L << " " << R << endl;
        // test statement //

        float l_time = a[0]+s;
        for(unsigned int j = 1; j < N; ++j)
        {
            unsigned long t = a[j]+s;
            if((j<L || j>R) && l_time < t)
                l_time = t;

            else if(l_time < float(t/2))
                l_time = float(t/2);
        }
        cout << std::fixed;
        cout << setprecision(1) << l_time << endl;

    }

    return 0;
}
