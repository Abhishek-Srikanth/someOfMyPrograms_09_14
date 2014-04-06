#include <iostream>
#define zero 0
using namespace std;

int main()
{
    int T = 0;
    cin >> T;
    while(T>0)
    {
        T--;
        long long N=0,K=0;
        cin >> N >> K;
        // N candies
        // K kids
        if(K!=0)
            cout << N/K << " " << N%K << endl;
        else cout << zero << " " << N << endl;
    }
    return 0;
}
