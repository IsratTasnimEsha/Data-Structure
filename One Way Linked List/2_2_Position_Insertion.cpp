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

void first_insert(int n)
{
    if(head==NULL)
    {
        creation(n);
        return;
    }

    Node *p = new Node();
    p->info = n;
    p->next = head;

    head = p;
}

void last_insert(int n)
{
    if(head==NULL)
    {
        creation(n);
        return;
    }

    Node *srt = head;

    while (srt->next != NULL)
        srt = srt->next;

    Node *p = new Node();
    p->info = n;
    p->next = NULL;

    srt->next = p;
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

void after_insert(int q, int n)
{
    int count=0;

    Node *srt = head;
    Node *srt2 = head->next;

    while (count!= q)
    {
        count++;

        if (srt->next == NULL)
        {
            cout << "NOT FOUND" << endl;
            return;
        }

        else
        {
            srt = srt->next;
            srt2 = srt2->next;
        }
    }

    Node *p = new Node();
    p->info = n;

    srt->next = p;
    p->next = srt2;
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
    int a[]={0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++)
        creation(a[i]);

    cout << "Initial list: ";
    traverse();

    //before_insert(0, 77);
    after_insert(1, 77);
    traverse();
}