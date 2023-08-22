// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node
{
public:
    ll info;
    Node *link;
};
Node *head, *temp;

void Creation(ll m)
{

    // creating new node
    Node *p = new Node();
    p->info = m;
    p->link = NULL;

    if (head == NULL)
    {
        // head points to new node p
        head = p;
        // head points to new node p. It will be changable and will be used to link new nodes.
        temp = p;
    }

    else
    {
        // link to new node
        temp->link = p;
        // points to next node
        temp = temp->link;
    }
}

void Traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << endl;
        srt = srt->link;
    }
    cout << endl;
}

int main()
{
    for (ll i = 0; i < 5; i++)
    {
        ll m;
        cin >> m;
        Creation(m);
    }

    Traverse();
}