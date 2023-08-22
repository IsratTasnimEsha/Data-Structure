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

ll peek(ll index)
{
    Node *ptr = head;

    ll count = 0;

    while (ptr != NULL && count != index)
    {
        cout << ptr->info << " ";
        ptr = ptr->link;

        count++;
    }

    if (ptr == NULL)
    {
        cout << "NOT FOUND" << endl;
        return -1;
    }

    else
        return ptr->info;
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

    cout << "Info at position 3: " << peek(45) << endl;
}