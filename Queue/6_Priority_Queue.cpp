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

    if(head==NULL)
    {
        head=p;
    }
    else
    {
        p->prev=NULL;
        p->next=head;
        head->prev=p;
    
        head=p;
    }
}

void before_insert(int q, int n)
{
    int count=1;

    Node *srt = head;
    Node *srt2 = head->next;

    while (count!=q)
    {
        count++;

        if (srt2->next == NULL)
        {
            cout << "NOT FOUND" << endl;
            return;
        }

        srt = srt->next;
        srt2 = srt2->next;
    }

    Node *p = new Node();
    p->info = n;

    srt->next = p;
    p->next = srt2;
}

void Push(int m)
{
    Node *srt=head;
    int count=0;

    while(srt->next!=NULL)
    {
        count++;

        if(m>=srt->info && m<=srt->next->info)
        {
            before_insert(count, m);
            break;
        }

        srt=srt->next;
    }
}

void Pop()
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
    Push(12);
    Push(6);
    Push(7);
    Push(10);
    //Pop();
    //Pop();
    //Push(9);
    Push(8);
    //Pop();

    Traverse();
    cout<<endl;
    reverseTraverse();
}