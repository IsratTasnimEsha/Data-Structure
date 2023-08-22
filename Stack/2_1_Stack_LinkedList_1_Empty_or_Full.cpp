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

ll isFull()
{
    Node *p = new Node();

    if (p == NULL)
        return 1;

    else
        return 0;
}

ll isEmpty()
{
    if (head == NULL)
        return 1;

    else
        return 0;
}

int main()
{
    Node *p=new Node();
    p->info=5;
    p->link=NULL;

    head=p;
    
    if (isEmpty())
        cout << "Stack is Empty." << endl;

    else
        cout << "Stack is not Empty." << endl;

    if (isFull())
        cout << "Stack is Full." << endl;

    else
        cout << "Stack is not Full." << endl;
}