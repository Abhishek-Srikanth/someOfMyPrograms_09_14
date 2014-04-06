#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

using namespace std;


class car
{
    public :
            string ocolor;
            string icolor;
            int fuel;
    void drive()
    {
        if (fuel <= 10)
        cout << "sorry can\'t drive" << endl;
        else
        {
            string word;
            cout << "\n\nenter your views on driving    put . or _ instead of space : " << endl;
            cin >> word;
            fuel = fuel - word.length();
            cout << "you have " << fuel << " litres of fuel left" << endl;
        }
    }

    void music(int x)
    {

        if (fuel <= 45)
        cout << "less fuel" << endl;
        else
        fuel -= 5*x;
        cout << "you have " << fuel << "litres left" << endl;
    }
};


#endif // CAR_H_INCLUDED
