#include <iostream>
#include <math.h>

int function(unsigned int a, unsigned int k)
{
    if(a%2==0)
    {
        while(a%2==0)
            a>>=1;
        k--;
    }
    if(a%3==0)
    {
        while(a%3==0)
            a/=3;
        k--;
    }
    int dec = -2, inc=4;
    for(unsigned int i = 5; i <=a ; i+=(unsigned int)inc)
    {
        if(a%i==0)
        {
            do
            {
                a/=i;
            }while(a%i==0);
            k--;
        }
        inc+=dec;
        dec*=-1;
    }
    if(k==0)
        return 1;
    else return 0;

}

int main()
{
    int T;
    std::cin >> T;
    while(T>0)
    {
        unsigned int A, B, K, counter=0;
        std::cin >> A >> B >> K;
        for(unsigned int I = A; I <= B; ++I )
        {
            counter += function(I, K);
        }
        std::cout << counter << "\n";
        --T;
    }
    return 0;
}
