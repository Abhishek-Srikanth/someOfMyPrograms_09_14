#include <iostream>

using namespace std;

class expenses
{
    public:
    int person_id;
    char name[20];
    int exp[7];
    expenses()
    {
        cout << "Enter name : ";
        cin.getline(name,20,'\n');
        cout << "Enter ID : ";
        cin >> person_id;
        cout << "Enter expenses : \n";
        for(int i = 0; i < 7; ++i)
        {
            cin >> exp[i];
        }
    }
};

void calcavg(expenses &a)
{
    int sum=0;
    for(int i = 0; i < 7; ++i)
        sum+=a.exp[i];
    cout << "Sum is " << sum << " and average is " << (float)sum/7 << endl;
}

int highexp(expenses &a)
{
    int h = 0,p=0;
    for(int i = 0; i < 7; ++i)
    {
        if(a.exp[i] > h)
        {
            h = a.exp[i];
            p=i;
        }
    }
    cout << "Highest cost was " << h << endl;
    return p+1;
}

int main()
{
    expenses a;
    calcavg(a);
    int day = highexp(a);
    cout << "day was " << day;
    return 0;
}
