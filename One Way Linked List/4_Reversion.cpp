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
Node *head, *tail=new Node();

void creation(ll m)
{
    Node *p = new Node(), *h_temp;
    p->info = m;
    p->link = NULL;

    if (head == NULL)
    {
        head = p;
        h_temp = p;
    }

    else
    {
        h_temp->link = p;
        h_temp = p;
    }
}

void reverse()
{
    Node *current=head;
    Node *prev=NULL, *next=NULL;

    while(current!=NULL)
    {
        next=current->link;
        current->link=prev;

        prev=current;
        current=next;
    }

    head=prev;
}

void traversal()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info<<" ";
        temp=temp->link;
    }
    cout<<endl<<endl;
}

int main()
{
    ll a[]={1, 2, 3, 4, 5};

    for (ll i = 0; i < 5; i++)
    {
        //ll n;
        //cin >> n;
        creation(a[i]);
    }
    traversal();
    reverse();
    traversal();
}