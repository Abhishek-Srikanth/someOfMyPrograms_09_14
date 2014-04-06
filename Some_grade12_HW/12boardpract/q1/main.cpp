#include <iostream>

using namespace std;

int size=0;

int push(int a[], int n)
{
    if(size==n){
        cout << "Overflow";
        return 1;}
    cout << "Enter value to be pushed : ";
    cin >> n;
    a[size++]=n;
    return 0;
}

int pop(int a[])
{
    if(!size){
        cout << "underflow";
        return 1;}
    size--;
    return 0;
}

void display(int a[])
{
    for(int i = 0; i < size; ++i)
        cout << a[i] <<"  ";
    cout << endl;
    if(!size)
        cout << "\nEMPTY\n";
}

int main()
{
    int n;
    cout << "enter the max size of stack : ";
    cin >> n;
    int linear_stack[n];
    push(linear_stack,n);
    push(linear_stack,n);
    push(linear_stack,n);
    push(linear_stack,n);

    display(linear_stack);
    pop(linear_stack);
    pop(linear_stack);
    display(linear_stack);
    pop(linear_stack);
    pop(linear_stack);
    display(linear_stack);
    return 0;
}
