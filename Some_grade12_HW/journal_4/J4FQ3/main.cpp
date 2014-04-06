#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class ph    // object to write
{
    public:
    char name[15];
    long long tel;
    ph()     // constructor
    {
        strcpy(name,"     ");
        tel = 0;
    }
};

int main()
{
    ifstream ifile("phonebook",ios::binary);
    ofstream ofile("phonebook",ios::binary);
    // above are filestreams to read and write respectively
    me:
    ifile.seekg(0);
    ofile.seekp(0);
    // above sets position to ZERO
    cout << "\n\nMENU : \n";
    // menu displayed
    cout << "1. Create records\n";
    cout << "2. Search by number\n";
    cout << "3. Update number\n";
    cout << "4. display\n";
    cout << "5. delete\n";
    cout << "6. exit\n";
    cout << "Enter your choice : ";
    char ch;
    cin >> ch;
        if(ch == '1')   // to create records
        {
                start:
                ph temp;
                cout << "Enter name : ";
                char name[15];
                cin >> name;
                strcpy(temp.name,name);
                cout << "Enter tel nubmer : ";
                cin >> temp.tel;

                ofile.write((char*)&temp, sizeof(ph));
                // write the read value to file

                cout << "do you wish to enter more : ";
                char p;
                cin >> p;
                if(p=='y'||p=='Y')
                    goto start;
                goto me;    // to go back to menu
        }

        if(ch=='2') // to search by tel number
        {
                cout << "Enter the tel no you wish to search for : ";
                long long ser;
                cin >> ser;
                int f=0;
                ifile.seekg(0);
                while(!ifile.eof())
                {
                    ph temp;
                    ifile.read((char*)&temp, sizeof(ph));
                    if(temp.tel==ser)
                    {
                        cout << "NAME : " << temp.name << " TEL : " << temp.tel << endl;
                        f=1;
                        break;
                    }
                }
                if(!f)  // in case nubmer is not found
                    cout << "such entry doesnot exist";
                goto me;
        }

        if(ch == '3')   // to change tel no by searching via name
        {
                int pos = 0;
                ifile.seekg(pos);
                char nam[15];
                cout << "Enter name to search for : ";
                cin >> nam;
                while(!ifile.eof())
                {
                    ph temp;
                    pos = ifile.tellg();
                    ifile.read((char*)&temp, sizeof(ph));
                    if(!strcmp(temp.name,nam))  // if name is found
                    {
                        cout << "Enter new telephone number : ";
                        cin >> temp.tel;
                        ofile.seekp(pos);
                        ofile.write((char*)&temp, sizeof(ph));
                        cout << "changes have been made !\n";
                        goto me;
                    }

                }
                cout << "Such entry does not exist";    // output if entry non-existant
                goto me;
        }

        if(ch == '4')   // to display all entries
        {
            ifile.seekg(0);
             while(!ifile.eof())
            {
                ph temp;
                ifile.read((char*)&temp, sizeof(ph));
                if(temp.tel!=0)
                    cout << "NAME : " << temp.name << " TEL : " << temp.tel << endl;
            }
            goto me;
        }
        // -------------------------------------------------
        // NOTE THAT END OF DISPLAY MAKED BY AN EMPTY OBJECT
        // -------------------------------------------------


        if(ch=='5')
        {
            ifile.seekg(0);
            ofile.seekp(0);
            int pos=0;
            char nam[15];
            cout << "Enter name to search for : ";
            cin >> nam;
            while(!ifile.eof())
            {
                ph temp;
                pos = ifile.tellg();
                ifile.read((char*)&temp, sizeof(ph));
                if(!strcmp(temp.name,nam))
                {
                    ofile.seekp(pos);
                    ph temp2;
                    ofile.write((char*)&temp2,sizeof(ph));
                    cout << "DELETED SPECIFIED VALUE";
                    goto me;
                }
            }
            cout << "couldn't locate data, deletion failed...";
            goto me;
        }



            cout << "\n\nTHANK YOU ... COME AGAIN SOON";

    return 0;
}
