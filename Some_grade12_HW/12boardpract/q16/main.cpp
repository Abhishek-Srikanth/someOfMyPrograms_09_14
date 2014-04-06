#include <iostream>
#include <string.h>

using namespace std;

struct DOB
{
    int d,m,y;
    void read()
    {
        cout << endl;
        cout << "Enter date  : ";
        cin >> d;
        cout << "Enter month : ";
        cin >> m;
        cout << "Enter year  : ";
        cin >> y;

    }
    void showdate()
    {
        cout << "date of birth : " << d << "/" << m << "/" << y << endl;
    }
};

class STUD
{
    unsigned int rno;
    float marks[3];
    float percentage;
    DOB date;
    public:
    char name[10];
    void create()
    {
        cout << "Enter rno : ";
        cin >> rno;
        cout << "Enter name : ";
        cin >> name;
        cout << "Enter marks : \n";
        cin >> marks[0] >> marks[1] >> marks[2];
        percentage = marks[0]+marks[1]+marks[2];
        percentage/=3;
        date.read();
    }
    void display()
    {
        cout << "Name : " << name << endl
             << "Rno  : " << rno  << endl
             << "mark1: " << marks[0] << endl
             << "mark2: " << marks[1] << endl
             << "mark3: " << marks[2] << endl
             << "perc : " << percentage << endl;
        date.showdate();
    }

};

int main()
{
    int n;
    cout << "Enter no of students : ";
    cin >> n;
    STUD a[10];
    for(int i = 0; i < n; ++i)
    {
        cout << "Enter data of " << i+1 << " : " << endl;
        a[i].create();
    }
    me:
    cout << "\n\n\tMENU\n1. show all students\n2. search by name\n3. add student to end\n4. exit\nso...";
    int ch;
    cin >> ch;
    switch(ch)
    {
        case 1:
        for(int i = 0; i < n; ++i)
        {
            a[i].display();
        }
        goto me;
        case 2:
        cout << "Enter name : ";
        char word[10];
        cin >> word;
        for(int i = 0; i < n; ++i)
        {
            if(strcmp(a[i].name,word)==0)
            {
                a[i].display();
                break;
            }
        }
        goto me;
        case 3:
        if(n<10)
        {
           a[n++].create();
        }
        goto me;
        case 4:
        cout << "bye";
    }


    return 0;
}
