#include <iostream>
#include <fstream>


using namespace std;

class camera
{
    long modelno;
    float megapixel;
    int zoom;
    char details[120];
    public:
    void enter()
    {
        cout << "Model Number : ";
        cin >> modelno;
        cout << "Megapixels : ";
        cin >> megapixel;
        cout << "Zoom : ";
        cin >> zoom;
        cout << "details : ";
        cin >> details;
    }

    void display()
    {
        cout << modelno << " - " << megapixel << " - " << zoom << " - " << details << endl;
    }

    long getmodelno()
    {
        return modelno;
    }
    void cmegapixel()
    {
        cout << "enter new megapixel : ";
        cin >> megapixel;
    }
    void ZERO()
    {
        modelno = 0;
        megapixel = 0;
        zoom = 0;
    }
};



int main()
{
    ofstream a("camera.dat",ios::binary);
    char ch = 'y';
    while(ch=='y')
    {
        camera x;
        x.enter();
        a.write((char*)&x, sizeof(camera));
        cout << "do you wish to enter again(y/n)?";
        cin >> ch;
    }

    ifstream in("camera.dat", ios::binary);


a.seekp(0);in.seekg(0);

    // display all
    while(!in.eof())
    {
        camera x;
        in.read((char*)&x, sizeof(camera));
        x.display();
    }


a.seekp(0);in.seekg(0);

    // to display camera based on model number
    cout << "Enter model no to search for : ";
    long m;
    cin >> m;
    while(!in.eof())
    {
        camera x;
        in.read((char*)&x, sizeof(camera));
        cout << 'a';
        if(x.getmodelno()==m)
            x.display();
    }


a.seekp(0);in.seekg(0);

    // to modify megapixel of camera
    cout << "Enter model no to search for : ";
    cin >> m;
    while(!in.eof())
    {
        camera x;
        a.seekp(in.tellg());
        in.read((char*)&x, sizeof(camera));
        if(x.getmodelno()==m)
        {
            x.cmegapixel();
            a.write((char*)&x,sizeof(camera));

        }
    }


a.seekp(0);in.seekg(0);

    // to delete specified element
    cout << "Enter model no to search for : ";
    cin >> m;
    while(!in.eof())
    {
        camera x;
        a.seekp(in.tellg());
        in.read((char*)&x, sizeof(camera));
        if(x.getmodelno()==m)
        {
            x.ZERO();
            a.write((char*)&x,sizeof(camera));
        }
    }


a.seekp(0);in.seekg(0);

    // display all
    while(!in.eof())
    {
        camera x;
        in.read((char*)&x, sizeof(camera));
        x.display();

    }

    return 0;
}
