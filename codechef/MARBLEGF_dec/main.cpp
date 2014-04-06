#include <cstdio>

using namespace std;

int main()
{

    int a = 5, b = 6;
    if(a = b)
    {
        printf("a=b\n");
    }
    /*
    int N, Q;
    scanf("%d %d", &N, &Q);
    ++Q;
    int A[N];
    for(int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }

    char query;
    int a = 0, b = 0;
    unsigned long sum = 0;

    while(Q>0)
    {
        scanf("%c %d %d", &query, &a, &b);

        if(query=='S')
        {
            sum = 0;
            for(;a <= b; ++a)
                sum += A[a];
            printf("%d\n", sum);
        }
        else if(query=='G')
        {
            A[a] += b;
        }
        else
            A[a] -= b;


        --Q;
    }
*/
    return 0;
}
