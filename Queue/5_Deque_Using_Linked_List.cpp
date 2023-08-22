// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *prev, *next;
} *head, *tail;

void push_Front(int n)
{
    Node *p=new Node();
    p->info=n;
    p->next=NULL;
    
    p->prev=NULL;
    p->next=head;
    head->prev=p;
    
    head=p;
}

void push_Back(int n)
{
    Node *p=new Node();
    p->info=n;
    p->next=NULL;
    
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=tail->next;
    }
}

void pop_Front()
{
    head=head->next;
    head->prev=NULL;
}

void pop_Back()
{
    tail=tail->prev;
    tail->next=NULL;
}

void Traverse()
{
    Node *srt=head;
    while(srt!=NULL)
    {
        cout<<srt->info<<" ";
        srt=srt->next;
    }
}

void reverseTraverse()
{
    Node *srt=tail;
    while(srt!=NULL)
    {
        cout<<srt->info<<" ";
        srt=srt->prev;
    }
}

int main()
{
    push_Back(6);
    push_Back(7);
    push_Back(8);
    pop_Front();
    pop_Front();
    push_Front(1);
    push_Front(45);
    push_Back(9);
    pop_Back();

    Traverse();
    cout<<endl;
    reverseTraverse();
}