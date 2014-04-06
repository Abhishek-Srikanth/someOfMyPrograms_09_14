#include <iostream>

using namespace std;

int main()
{
    int x;
    cout << "type your desired number here: " << endl;
    cin >> x;

    if (x>0)
    {
        cout << "your number is greater than zero and so is positive" << endl;
    }

    else if (x<0)
    {
        cout << "your value is a negative number" << endl;
    }

    else
    {
        cout << "your value is zero" << endl;
    }
    return 0;
}
