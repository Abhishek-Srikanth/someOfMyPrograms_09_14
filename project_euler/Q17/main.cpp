#include <iostream>

using namespace std;

// const int one = 3, two = 3, three = 5, four = 4, five = 4, six = 3, seven = 5, eight = 5, nine= 4;

int alpha(int &n)
{
    int d1=0, d2=0, d3=0;
    d3 = n%10;
    if(n>9)
        d2 = (n%100 - d3)/10;
    if(n>99)
        d1 = (int)(n/100);
    int val=0;

    switch(d1)
    {
        case 1:
            val += 3 + 10;
            break;
        case 2:
            val += 3 + 10;
            break;
        case 3:
            val += 5 + 10;
            break;
        case 4:
            val += 4 + 10;
            break;
        case 5:
            val += 4 + 10;
            break;
        case 6:
            val += 3 + 10;
            break;
        case 7:
            val += 5 + 10;
            break;
        case 8:
            val += 5 + 10;
            break;
        case 9:
            val += 4 + 10;
            break;
    }

    if(d2==1)
    {
        if(d3==1 || d3==2)
            val+= 6;
        else if(d3==3 || d3==4 ||  d3==8 || d3==9)
            val += 8;
        else if(d3==5 || d3==6)
            val += 7;
        else if(d3==7)
            val += 9;
        else if(d3==0)
            val+=3;

        cout << d1 << d2 << d3 << " - ";
        cout << n << " has " << val << " alphabets\n";
        return val;
    }

    switch(d2)
    {
            case 2:
                val += 6;
                break;
            case 3:
                val += 6;
                break;
            case 4:
                val += 5;
                break;
            case 5:
                val += 5;
                break;
            case 6:
                val += 5;
                break;
            case 7:
                val += 7;
                break;
            case 8:
                val += 6;
                break;
            case 9:
                val += 6;
                break;
    }


        switch(d3)
        {
            case 1:
                val += 3;
                break;
            case 2:
                val += 3;
                break;
            case 3:
                val += 5;
                break;
            case 4:
                val += 4;
                break;
            case 5:
                val += 4;
                break;
            case 6:
                val += 3;
                break;
            case 7:
                val += 5;
                break;
            case 8:
                val += 5;
                break;
            case 9:
                val += 4;
                break;
        }
    cout << d1 << d2 << d3 << " - ";
    cout << n << " has " << val << " alphabets\n";
    return val;
}

int main()
{
    long sum =0;

    for(int i = 1; i < 100; ++i)
    {
        sum += alpha(i);
    }
    sum += 11;
    cout << "\nSum is : " << sum;
    return 0;
}
// then solved mathematically
// 99 digits per century
// 0 - 8650
// 1 - 13*99
// 2 - 13*99
// 3 - 15*99
// 4 - 14*99
// 5 - 14*99
// 6 - 13*99
// 7 - 15*99
// 8 - 15*99
// 9 - 14*99
