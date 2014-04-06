#include <iostream>

struct node
{
    int val;
    node *link;
}*top = NULL;

void push()
{
    node *temp = new node;
    std::cout << "Enter value: ";
    std::cin >> temp->val;
    temp->link = top;
    top = temp;
}

void pop()
{
    if(top!=NULL)
    {
        node *p = top;
        top = top->link;
        std::cout << "\ndeleting :" << p->val;
        delete p;
    }
    else
        std::cout << "underflow";
}

void display()
{
    node *n = top;
    while(n!=NULL)
    {
        std::cout << n->val << "  " ;
        n = n->link;
    }
}

void memclear()
{
    while(top!=NULL)
    {
        pop();
    }
}

int main()
{
    int i;
    st:
    std::cout<< "\nEnter choice : ";
    std::cin >> i;
    if(i==1)
    {
        push();
        goto st;
    }
    if(i==2)
    {
        pop();
        goto st;
    }
    if(i==3)
    {
        display();
        goto st;
    }
    else
        memclear();
}
