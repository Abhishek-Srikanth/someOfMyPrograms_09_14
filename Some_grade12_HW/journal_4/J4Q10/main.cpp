#include <iostream>

using namespace std;

class bank
{
    int ID;
    float savings;
    public:
    bank operator+ (bank a) // operator definition
    {
        if(this->ID==a.ID)  // use of *this function
        {
            this->savings += a.savings;
            a.savings=0;
        }
        else
            cout << "illegal transaction due to mismatch of ID\n";
    };

    bank(int a, float b) : ID(a),savings(b){}   // constructor

    void display()          // display function
    {
        cout << "Your ID is " << ID << endl;
        cout << "Your current saving is " << savings << endl << endl;
    }
};

int main()
{
    cout << "This program emulates a banking situation where there are many\n"
         << "banks and eack bank has accounts represented by an ID that is\n"
         << "used to identify a person. *this is used in operator function+\n"
         << "that adds to your account (here abhishek) the savings in each bank\n\n";

    bank HDFC(12,300),HSBC(12,9999),DBS(12,19945),AVIVA(11,1000);
    // above are the many banks present
    // below is the account of person "abhishek"
    bank abhishek(12,0);
    abhishek + HDFC;
    abhishek.display();
    abhishek + HSBC;
    abhishek.display();
    abhishek + DBS;
    abhishek.display();
    abhishek + AVIVA;
    abhishek.display(); // display ID and savings after each transaction

    return 0;
}
