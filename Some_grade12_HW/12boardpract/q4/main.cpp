#include <iostream>

using namespace std;

struct node
{
    int val;
    node *next;
};

class queue
{
    node *head, *tail;
    public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }
    void add();
    void del();
    void disp();
    ~queue()
    {
        node *n = head;
        while(head!=NULL)
        {
            n = head;
            head = head->next;
            cout << n->val << " ";
            delete n;
        }
    }
};

void queue::add()
{
    node *n = new node;
    cout << "Enter value of new entry : ";
    cin >> n->val;
    n->next = NULL;

    if(head == NULL)
    head = tail = n;
    else
    {
        tail->next = n;
        tail =n;
    }
}

void queue::del()
{
    node *t = head;
    head = head->next;
    if(t!=NULL)
    {
        cout << "\ndeleting " << t->val << endl;
        delete t;
    }
    else cout << "queue is empty";
}

void queue::disp()
{
    node *n = head;
    while(n!=NULL)
    {
        cout << n->val << "  ";
        n = n->next;
    }
}

int main()
{
    queue a;
    top:
    cout << "\n\n1->add\n2->del\n3->disp\n4->bye\n\nyour choice : ";
    int i;
    cin >> i;
    switch(i)
    {
        case 1:
                a.add();
                goto top;
        case 2:
                a.del();
                goto top;

        case 3:
                a.disp();
                goto top;

        case 4:
                cout << "adios!\n;";
    }
    return 0;
}
