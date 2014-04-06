#include <iostream>

using namespace std;

class Complex
{
    float real, image;
    public:
    Complex(float a=0, float b=0) : real(a), image(b){}

    Complex operator + (Complex q)
    {
        Complex ret;
        ret.real = this->real + q.real;
        ret.image = this->image + q.image;
        return ret;
    }
    Complex operator - (Complex q)
    {
        Complex ret;
        ret.real = this->real - q.real;
        ret.image = this->image - q.image;
        return ret;
    }

    void display()
    {
        cout << endl << real << " + i." << image << endl;
    }

    Complex operator *(Complex q)
    {
        Complex ret;
        ret.real = (this->real * q.real) - (this->image * q.image);
        ret.image = (this->real * q.image) + (this->image * q.real);
        return ret;
    }

    Complex operator /(Complex q)
    {
        Complex ret;
        ret.real = (this->real * q.real) + (this->image * q.image);
        ret.image = (-1)*(this->real * q.image) + (this->image * q.real);
        ret.real/=(q.real)*(q.real) + (q.image)*(q.image);
        ret.image/=(q.real)*(q.real) + (q.image)*(q.image);
        return ret;
    }


};

int main()
{
    float r,ur; // real and unreal for inputs! //
    cout << "Enter your number (real <space> imaginary) : ";
    cin >> r >> ur;
    Complex a(r,ur);
    tom:
    cout << "\nMENU\n1.add\n2.sub\n3.mul\n4.div\n5.ext\n\nenter choice : ";
    cin >> r;
    switch((int)r)
    {
        case 1:
            cout << "Enter number to add (real <space> imaginary) : ";
            cin >> r >> ur;
            a = a + Complex(r,ur);
            cout << "Your number is : ";
            a.display();
            cout << "\n\n";
            goto tom;
        case 2:
            cout << "Enter number to subtract (real <space> imaginary) : ";
            cin >> r >> ur;
            a = a - Complex(r,ur);
            cout << "Your number is : ";
            a.display();
            cout << "\n\n";
            goto tom;

        case 3:
            cout << "Enter number to multiply (real <space> imaginary) : ";
            cin >> r >> ur;
            a = a * Complex(r,ur);
            cout << "Your number is : ";
            a.display();
            cout << "\n\n";
            goto tom;

        case 4:
            cout << "Enter number to divide (real <space> imaginary) : ";
            cin >> r >> ur;
            a = a / Complex(r,ur);
            cout << "Your number is : ";
            a.display();
            cout << "\n\n";
            goto tom;

        case 5:
            cout << "Bye";
    }


    return 0;
}
