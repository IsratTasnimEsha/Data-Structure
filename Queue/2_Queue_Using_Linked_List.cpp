// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *link;
} *head, *tail;

void Enque(int n)
{
    Node *p=new Node();
    p->info=n;
    p->link=NULL;
    
    if(head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->link=p;
        tail=tail->link;
    }
}
void Deque()
{
    head=head->link;
}
void Traverse()
{
    Node *srt=head;
    while(srt!=NULL)
    {
        cout<<srt->info<<" ";
        srt=srt->link;
    }
}
int main()
{
    Enque(6);
    Enque(7);
    Enque(8);
    Deque();
    Enque(6);
    Enque(7);
    Deque();
    Deque();
    Enque(8);

    Traverse();
}