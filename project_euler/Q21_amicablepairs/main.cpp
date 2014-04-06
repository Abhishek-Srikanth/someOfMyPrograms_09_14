#include <iostream>

using namespace std;

int d(int i)
{
    int sum = 0, c = 1;
    while(c < i)
    {
        if(i%c==0)
            sum+= c;
        ++c;
    }
    return sum;
}

int main()
{
    long sum = 0;
    for(int i = 1; i < 10000; ++i)
        if( d(d(i)) == i && i!=d(i) )
            sum += i;

    cout << "sum of all amicable number is : " << sum << endl;
    return 0;
}
