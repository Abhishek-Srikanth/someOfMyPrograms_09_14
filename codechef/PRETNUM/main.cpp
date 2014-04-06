#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

int isPrime(int prime)
{
    int c = 0;
    for(int i = 1; i <= prime; ++i)
    {
        if(prime%i==0)
            ++c;
    }
    if(c==2)
        return 1;
    else
        return 0;
}

int nDiv(unsigned long long int &num)
{
    int prime=0;
    for(int i = 1; i <= num; ++i)
        if(num%i==0)
            ++prime;
    if(isPrime(prime))
        return 1;
    else
        return 0;
}

int main()
{
    ofstream file("binary.txt", ios::out);
    for(unsigned long long int i = 0; i < 1000000000001; ++i)
    {
        int k = nDiv(i);
        cout << i << " : " << k << endl;
        file << k;
    }
    file.close();
    return 0;
}
