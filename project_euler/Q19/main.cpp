#include <iostream>

using namespace std;

enum DAY{monday=1, tuesday, wednesday, thursday, friday, saturday, sunday};
enum MONTH{Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

int main()
{
    int counter=0;
    unsigned int date = 1, year = 1900;
    DAY day = monday;
    int month = Jan;

    while(year<2001)
    {
        if(date==1 && day==sunday && year>=1901)
        {
            counter++;
        }

        date++;

        switch(day)
        {
            case 1:
                day = tuesday;
                break;
            case 2:
                day = wednesday;
                break;
            case 3:
                day = thursday;
                break;
            case 4:
                day = friday;
                break;
            case 5:
                day = saturday;
                break;
            case 6:
                day = sunday;
                break;
            case 7:
                day = monday;
                break;
        }

        if(month!=Feb && month!= Apr && month!=Jun && month!=Sep && month!=Nov && date==32)
        {
            date=1;
            month+=1;
            if(month==13)
            {
                month=Jan;
                year++;
            }
        }
        else if( (month==Apr || month==Jun || month==Sep || month==Nov) && date==31)
        {
            date = 1;
            month++;
        }
        else if(month==Feb)
        {
            if(year==1900 && date == 29)
            {
                date = 1;
                month = Mar;
            }
            else if(year%4==0 && date==30)
            {
                date = 1;
                month++;
            }
            else if(date==29)
            {
                date = 1;
                month++;
            }
        }
        cout << "Today : " << date << " - " << month << " - " << year << " a " << day << endl;

    }
    cout << counter;
    return 0;
}
