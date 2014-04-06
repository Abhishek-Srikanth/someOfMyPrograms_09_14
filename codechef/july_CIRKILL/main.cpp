#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

struct point
{
    float x,y;
};

bool circle(point &T1, point &T2, point &T3, point ash)
{
    float slopeC12 = (T1.x - T2.x)/(T2.y - T1.y);
    float slopeC23 = (T2.x - T3.x)/(T3.y - T2.y);
    point T12;
    T12.x = (T1.x + T2.x)/2;
    T12.y = (T1.y + T2.y)/2;
    point T23;
    T23.x = (T2.x + T3.x)/2;
    T23.y = (T2.y + T3.y)/2;

    float a = (slopeC12*T12.x) - (slopeC23*T23.x) + T23.y - T12.y;
    a /= ( slopeC12 - slopeC23 ) ;
    float b = slopeC12*( a - T12.x) + T12.y;
    float radius = sqrt( (T1.x - a)*(T1.x - a) + (T1.y - b)*(T1.y - b) );

//  cout << "a,b : " << a << " , " << b << "\nradius is " <<radius << endl;

    float dist = sqrt( (a - ash.x)*(a - ash.x) + (b - ash.y)*(b - ash.y) );
    if(dist<=radius)
        return 1;
    else return 0;
}

int function()
{
    int N;
    cin >> N;
    int t1=0,t2=1,t3=2;

    point Tile[N];
    for(int i =0; i < N; ++i)
    {
        cin >> Tile[i].x >> Tile[i].y;
    }

    float trial=0; // is the number of combination of cirlces
    float kill =0; // is the number of times ash is on circle
    while(t1<(N-2))
    {

        if((Tile[t1].x==Tile[t2].x && Tile[t2].x==Tile[t3].x) || (Tile[t1].y==Tile[t2].y && Tile[t2].y==Tile[t3].y))
        {
                trial+=N-3;
            goto b;
        }

        for(int ash = 0; ash < N; ++ash)
        {
            if(ash==t1 || ash==t2 || ash==t3)
                continue;
            else    // a successfull combiination
            {
                kill += circle(Tile[t1], Tile[t2], Tile[t3], Tile[ash]);
                trial++;
            }
        }
        b:
        t3++;
        if(t3==N)
        {
            t2++;
            t3=t2+1;
            if(t2==N-1)
            {
                t1++;
                t2=t1+1;
                t3=t1+2;
            }
        }
    }

    cout << kill/trial << "\n";
    return 0;
}

int main()
{
    int T;
    cin >> T;
    while(T>0)
    {
        function();
        --T;
    }
    return 0;
}
