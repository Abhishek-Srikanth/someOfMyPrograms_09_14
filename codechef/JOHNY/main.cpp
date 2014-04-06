#include <iostream>

using namespace std;

long int array[100];
int N, K, c2;

void loop()
{
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        cin >> array[i];
    }

    cin >> K;
    int val_K = array[K-1];


    c2=0;
    for(int i = K; i < N; ++i)
    {
        if(array[i] < val_K)
            ++c2;
    }
    for(int i = 0; i < K; ++i)
    {
        if(array[i] > val_K)
            --c2;
    }
    cout << K+c2 << "\n";
}

int main()
{
    int T;
    cin >> T;
    while(T>0)
    {
        --T;
        loop();
    }
}
