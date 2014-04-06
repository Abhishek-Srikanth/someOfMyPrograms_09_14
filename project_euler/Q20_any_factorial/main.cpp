#include <iostream>
#include <vector>

using namespace std;

int factorial(int a)
{
    vector<int> num (1,1);

    for(int i = 1; i <=a; ++i)
    {
        int carry = 0;
        for(int j = 0; j < num.size(); ++j)
        {
            num[j] = (num[j]*i) + carry;
            carry = (num[j] - num[j]%10)/10;
            num[j]%=10;
        }
        while(carry!=0)
        {
            num.push_back(0);
            num[num.size()-1] = (num[num.size()-1]*i) + carry;
            carry = (num[num.size()-1] - num[num.size()-1]%10)/10;
            num[num.size()-1]%=10;
        }

    }
    long long sum=0;
    for(int i = 0; i < num.size(); ++i)
    {
        if(i%60==0)
            cout << endl;
        cout << num[i];
        sum +=num[i];
    }
    cout << "\n\nsum is : " << sum;
    cout << "\nnumber of digits is : " << num.size();
    return 0;
}

int main()
{
    cout << "Enter number whose factorial is needed : ";
    int a;
    cin >> a;
    factorial(a);
    cout << endl << "NOTE: read from last to front!";
    return 0;
}
