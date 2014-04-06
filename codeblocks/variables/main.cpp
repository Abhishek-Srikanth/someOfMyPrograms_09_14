#include <iostream>

using namespace std;

int main()
{
    int t=10,d=20,h=3254,tdh=t+d+h;
    cout << "values have been given for t, d and h." << endl;
    cout << t << endl;
    cout << h << endl;
    cout << d << endl;
    cout << tdh << endl;
    cout << "the value of t has been changed" << endl;
    t=1;
    tdh=t+d+h;
    cout << t << endl;
    cout << "tdh has been respecified as equal to t + d + h" << endl;
    cout << tdh << endl;
    cout << "value of h has been changed by making it sum of t and d" << endl;
    h=d+t;
    cout << h << endl;
    cout << "changing t value as the same as value of h" << endl;
    t=h;
    cout << t << "\t" << h << endl;
    cout << "now we will add two variables" << endl;
    cout << t+d << endl;
    cout << "now we will subtract variable" << endl;
    cout << t-h << endl;
    cout << "now multiplication" << endl;
    cout << h*t << endl;
    cout << "division" << endl;
    cout << t/d << endl;
    cout << "value of t will be increased and h will be reduced by one" << endl;
    t++;
    h--;
    cout << t << h << endl;
    cout << "now d will be added with 10" << endl;
    d+=10;
    cout << d << endl;
    cout << "now i will work on quotient and remainders." << endl;
    cout << "first quotient will be specified and then remainder for 5 \/ 3" << endl;
    cout << 5/3 << endl;
    cout << 5%3 << endl;
    char a='\0';
    cout << a << endl;
    char x = '\t';
    cout << t << x << d << x << h << a << endl;
    return 0;
}
