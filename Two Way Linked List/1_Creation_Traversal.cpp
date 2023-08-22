// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

class Node
{
public:
    ll info;
    Node *prev, *next;
} * head, *tail;

void creation(ll m)
{
    Node *p = new Node();
    p->prev = NULL;
    p->info = m;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        tail = p;
    }

    else
    {
        tail->next = p;
        p->prev = tail;
        tail = tail->next;
    }
}

void traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->next;
    }

    cout << endl;
}

void reverse_traverse()
{
    Node *srt = tail;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->prev;
    }

    cout << endl;
}

int main()
{
    //ll a[] = {1, 2, 3, 4, 5};

    for (ll i = 0; i < 5; i++)
    {
        ll a;
        cin>>a;
        creation(a);
    }

    traverse();
    reverse_traverse();
}