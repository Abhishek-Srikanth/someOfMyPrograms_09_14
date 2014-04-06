#include <iostream>

using namespace std;

int main()
{
    unsigned short num[350] = {0};
    unsigned short carry = 0;
    num[0] = 2;
    for(int pow = 2; pow<=1000; ++pow)
    {
        for(int idx=0; idx<350; ++idx)
        {
            num[idx] = (num[idx]*2) + carry;
            carry=0;
            if(num[idx]>9)
            {
                carry = num[idx]/10;
                num[idx]%=10;
            }
        }
        cout << "power = " << pow << endl;
    }

    long long sum=0;
    for(int i = 0; i < 350; ++i)
    {
        sum+=num[i];
        cout << num[i];
        if(i%70==0)
            cout << endl;
    }
    cout << "\n\n" << sum;

    {
        delete[] num;
        return 0;
    }
}
