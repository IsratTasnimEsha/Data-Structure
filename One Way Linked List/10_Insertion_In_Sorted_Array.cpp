/// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
} * head, *temp;

void creation(int m)
{
    Node *p = new Node();
    p->info = m;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        temp = p;
    }

    else
    {
        temp->next = p;
        temp = temp->next;
    }
}

void linear_search(int m)
{
    Node *p=new Node();
    p->info=m;

    if(p->info<=head->info)
    {
        p->next=head;
        head=p;
        return;
    }
    Node *srt1=head, *srt2=head->next;
    while(srt2->next!=NULL)
    {
        if(srt1->info<=m && srt2->info>m)
        {
            srt1->next=p;
            p->next=srt2;
            return;
        }
        srt1=srt1->next;
        srt2=srt2->next;
    }
    if(srt2->next==NULL) srt2->next=p;
}

void traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->next;
    }

    cout << endl
         << endl;
}

int main()
{
    int a[]={22, 44, 66, 88, 99};

    for (int i = 0; i < 5; i++)
        creation(a[i]);

    cout << "Initial list: ";
    traverse();

    linear_search(151);
    traverse();
}