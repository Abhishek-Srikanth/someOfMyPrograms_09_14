#include <iostream>

using namespace std;

int main()
{
    int p1;
    int p2;
    cout << "player one, please enter a number of your choice:" << endl;
    cin >> p1;
    cout << endl;
    cout << "player 2, please enter a number of your choice:" << endl;
    cin >> p2;
    cout << endl;
    string ans = (p1 == p2) ? "Both the values are the same, congratulations. You two think alike" : "Sorry, but both of your answers do not match" ;
    cout << ans << endl;
    cout << endl;
    cout << "the value of player one subtracted by player two is: " << p1 - p2 << endl;
    cout << endl;
    cout << "the sum of both values is: " << p1 + p2 << endl;
    cout << endl;
    cout << "the product of both numbers is: " << p1 * p2 << endl;
    cout << endl;
    cout << "the average of your two numbers is:" << (p1 + p2)/2 << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    return 0;
}
