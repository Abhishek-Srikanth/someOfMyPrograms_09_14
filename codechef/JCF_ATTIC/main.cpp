#include <iostream>

using namespace std;

void m()
{
    char ch='#';
    int c = 0;
    int L = 0;
    int days = 0;
    for(;;)
    {
        cin.get(ch);
        if(ch=='.')
        {
            ++c;
        }
        else if(ch=='#')
        {
            if(c>L)
            {
                L=c;
                days++;
            }
            c=0;
        }
        else
            break;
    }
    cout << days << endl;
}

int main()
{
    long int T;
    cin >> T;
    char ch;
    cin >> ch;
    for(long int i = 0; i < T; ++i)
    {
        m();
    }
    return 0;
}
