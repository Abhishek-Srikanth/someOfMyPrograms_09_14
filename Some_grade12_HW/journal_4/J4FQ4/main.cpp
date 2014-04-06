#include <iostream>
#include <fstream>

using namespace std;

class object
{
    int integer;
    char character;
    float floating_point;
    public:
    object()   // constructor1
    {
        integer = 0;
        character = '0';
        floating_point = 0.00;
    }
    object(int a, char b, float c) : integer(a) , character(b) , floating_point(c){}
    // constructor2
    void Disp() // display function
    {
        cout << "object is : "<< integer << " - " <<  character << " - " << floating_point << endl;
    }
};

int main()
{
    ofstream a("random_file" , ios::binary | ios::app);
    // random file DOES HAVE PRE.existing values
    char ch='y';
        int x;
        char y;
        float z;

    while(1)    // loop writes until users says stop
    {
        cout << "Enter int, char, float : ";
        cin >> x >> y >> z;
        object q(x,y,z);
        a.write((char*)&q, sizeof(object));
        cout << "Do you wanna continue : ";
        cin >> ch;
        if(ch=='n' || ch == 'N')
            break;
    }

    a.close();  // file a colsed

    ifstream aa("random_file" , ios::binary);
    while(!aa.eof())    // reads until end of file
    {
        object c;
        aa.read((char*)&c,sizeof(object));
        c.Disp();
    }
    // reading terminates with display of 0 - 0 - 0
    aa.close();
    return 0;
}
