#include <iostream>

using namespace std;

int main()
{
    /**
    int n = 123401;
    cout << "6th digit is " << n%10;
    cout << "\n5th digit is " << n%100/10;
    cout << "\n4th digit is " << n%1000/100;
    cout << "\n3th digit is " << n%10000/1000;
    cout << "\n2th digit is " << n%100000/10000;
    cout << "\n1th digit is " << n%1000000/100000;
    */

    int largest = 0;

    for(int i = 100; i <= 999; ++i)
    {
        for(int j = 100; j <= 999; ++j)
        {
            int n = i*j;
            if(n>=100000)   // ie. 6 digit
            {
                if( (n%1000000/100000)==(n%10) && (n%100000/10000)==(n%100/10) && (n%10000/1000)==(n%1000/100) )
                {
                    cout << i << "x" << j << " = " << i*j << endl;
                    if(i*j>largest)
                        largest = i*j;
                }
            }
            else
            {
                if( (n%100000/10000)==(n%10) && (n%10000/1000)==(n%100/10) )
                {
                    cout << i << "x" << j << " = " << i*j << endl;
                    if(i*j>largest)
                        largest = i*j;
                }
            }
        }
    }
    cout << endl << endl << "LARGEST IS " << largest << endl;
    return 0;
}
