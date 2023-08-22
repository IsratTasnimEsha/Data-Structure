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
    
    temp->link=head;
}

void Traverse()
{
    Node *srt = head;

    do
    {
        cout << srt->info << " ";
        srt = srt->link;
    } while (srt != head);
}

int main()
{
    ll a[] = {2, 4, 6, 7, 8};

    for (ll i = 0; i < 5; i++)
        Creation(a[i]);

    cout<<"List: ";
    Traverse();
}