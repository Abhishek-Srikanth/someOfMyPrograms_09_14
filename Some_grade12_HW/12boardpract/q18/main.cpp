#include <iostream>
#include <fstream>

using namespace std;

class USER
{
    int Uid;
    char uname[20];
    char status;
    public:
    void Register()
    {
        cout << "Enter Uid : ";
        cin >> Uid;
        cout << "uname : ";
        cin >> uname;
        cout << "Enter status ; ";
        cin >> status;
    }
    void show()
    {
        cout << "Id     : " << Uid << endl;
        cout << "Name   : " << uname << endl;
        cout << "Status : " << status << endl;
    }
    char getstatus(){return status;}
};

void print()
{
    ofstream out("user.dat", ios::binary | ios::app);
    USER a;
    for(int i = 0; i < 5; ++i)
    {
        a.Register();
        out.write((char*)&a, sizeof(USER));
    }
}

int main()
{
    ifstream in("user.dat", ios::in|ios::binary);
    USER *a = new USER;
    while(!in.eof())
    {
        in.read((char*)a, sizeof(USER));
        if(a->getstatus() == 'A')
            a->show();
    }

    delete a;
    return 0;
}
