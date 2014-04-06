#include <iostream>

using namespace std;

int main()
{
    for(int a = 100;a<1000; ++a)
    {
        for(int b = 100;b<1000; ++b)
        {
            for(int c = 100;c<1000; ++c)
            {
                if(a+b+c==1000 && ((a*a) + (b*b) == (c*c)))
                {
                    cout << "a : " << a << endl;
                    cout << "b : " << b << endl;
                    cout << "c : " << c << endl;
                    cout << "answer is " << a*b*c;
                    return 0;
                }
            }
        }
    }
    return 0;
}
