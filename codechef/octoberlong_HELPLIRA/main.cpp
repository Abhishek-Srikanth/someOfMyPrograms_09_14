#include <iostream>

using namespace std;

int main()
{
    short T;
    cin >> T;
    int min_Area=999999999, min_index=-1;
    int max_Area=0, max_index=-1;
    for(int i = 0; i < T; ++i)
    {
        int x1,x2,x3,y1,y2,y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        int Area = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
        Area/=2;
        (Area<0)?(Area*=-1):(Area*=1);
        if(Area <= min_Area)
        {
            min_Area = Area;
            min_index = i;
        }
        if(Area >= max_Area)
        {
            max_Area = Area;
            max_index = i;
        }
    }
    cout << min_index+1 << " " << max_index+1 << endl;
    return 0;
}
