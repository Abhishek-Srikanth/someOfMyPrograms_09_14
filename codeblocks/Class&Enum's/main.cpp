#include <iostream>
#include "car.h"


using namespace std;

int main()
{
    car ferrari;
    ferrari.ocolor = "blue";
    cout << "it has got an exterior color of " << ferrari.ocolor << endl;
    ferrari.icolor = "red";
    cout << "it has got an interior color of " << ferrari.icolor << endl;
    ferrari.fuel = 100;
    cout << "fuel = " << ferrari.fuel;
    ferrari.drive();
    cout << "how much music do you listen in your car \(in hours please\)? " << endl;
    int x;
    cin >> x;
    ferrari.music(x);
    car nissan;
    nissan.ocolor="blue";
    cout << "it has an extertior color of : " << nissan.ocolor<<endl;
    nissan.icolor="black";
    cout << "It has an interior color of : " << nissan.icolor << endl;

    return 0;
}


