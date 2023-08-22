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

void add_1()
{
    reverse();

    if(head->info!=9) head->info+=1;

    else
    {
        Node *srt=head;
        while(srt->link!=NULL)
        {
            if(srt->info==9) srt->info=0;
            else break;
            srt=srt->link;
        }
        if(srt->info!=9) srt->info+=1;
        else
        {
            srt->info=0;
            Node *p=new Node();
            p->info=1;
            p->link=NULL;
            srt->link=p;
        }
    }

    reverse();
}
void traversal()
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->info;
        temp=temp->link;
    }
    cout<<endl<<endl;
}

int main()
{
    ll a[]={3, 9, 5, 9};

    for (ll i = 0; i < 4; i++)
    {
        //ll n;
        //cin >> n;
        creation(a[i]);
    }
    add_1();
    traversal();
    //reverse();
    //traversal();
}