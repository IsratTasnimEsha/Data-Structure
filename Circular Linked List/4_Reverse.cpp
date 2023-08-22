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

void creation(ll m)
{
    Node *p = new Node();
    p->info = m;
    p->link = head;

    if (head == NULL)
    {
        head = p;
        temp = p;
    }

    else
    {
        temp->link = p;
        temp = temp->link;
    }
    temp->link = head;
}

void traverse()
{
    Node *srt = head;

    while (srt->link != head)
    {
        cout << srt->info << " ";
        srt = srt->link;
    }

    if (srt->link == head)
        cout << srt->info << endl;
}

void reverse()
{
    Node *current = head;
    Node *prev = NULL, *next = NULL;

    do
    {
        next = current->link;
        current->link = prev;

        prev = current;
        current = next;
    } while (current != head);

    head->link = prev;
    head = prev;
}

int main()
{
    ll a[] = {1, 2, 3, 4, 5};

    for (ll i = 0; i < 5; i++)
    {
        // ll n;
        // cin >> n;
        creation(a[i]);
    }
    traverse();
    reverse();
    traverse();
    traverse();
}