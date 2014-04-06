#include <iostream>

using namespace std;

int main()
{
    long long num = 600851475143;
    long largest = 0;
    for(long i = 3; i <= num; i++)
    {
        if(num%i==0)
        {
            largest=i;
            cout << i << endl;
            while(num%i==0)
            {
                num/=i;
            }
        }
    }
    cout << endl << "largest is : ";
    cout << largest;
    return 0;
}
