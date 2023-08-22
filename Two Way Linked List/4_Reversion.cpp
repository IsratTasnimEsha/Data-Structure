// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
        //cout << srt << " ";
        cout << srt->info << " ";
        srt = srt->next;
    }

    cout << endl<<endl;
}

void reverse()
{
    Node *srt = head, *ptr;

    while(srt!=NULL)
    {
        ptr=srt->prev;
        srt->prev=srt->next;
        srt->next=ptr;

        srt=srt->prev;
        //cout<<ptr<<" ";
    }
    //cout<<endl;
    //cout<<ptr<<" "<<ptr->info<<endl;

    head=ptr->prev;
}

int main()
{
    ll a[]={1, 2, 3, 4, 5};

    for(ll i=0; i<5; i++) creation(a[i]);

    traverse();    
    reverse();
    traverse();    
}