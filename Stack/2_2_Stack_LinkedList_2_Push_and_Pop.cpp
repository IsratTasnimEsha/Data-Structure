// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node
{
public:
    ll info;
    Node *link;
} * head;

void push(ll m)
{
    Node *p = new Node();

    if (p == NULL)
        cout << "Stack Overflow." << endl;

    else
    {
        p->info = m;
        p->link = head;
        head = p;
    }
}

ll pop()
{
    if (head == NULL)
    {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    else
    {
        Node *p = head;

        head = head->link;

        return p->info;
    }
}

void Traverse()
{
    Node *ptr = head;

    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

int main()
{
    ll a[] = {6, 15, 24, 36, 48, 57, 63, 74, 89, 95};

    for (ll i = 0; i < 10; i++)
        push(a[i]);

    cout << "list: ";
    Traverse();

    cout << pop()<<endl;
    cout << pop()<<endl;
    cout << pop()<<endl;
    cout << pop()<<endl;
    
    cout << "list: ";
    Traverse();
}