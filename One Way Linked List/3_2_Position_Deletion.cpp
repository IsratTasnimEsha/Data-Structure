// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

class Node
{
public:
    ll info;
    Node *link;
} * head, *temp;

void creation(ll m)
{
    Node *p = new Node();
    p->info = m;
    p->link = NULL;

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
}

void traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->link;
    }

    cout << endl
         << endl;
}

void first_delete()
{
    head = head->link;
}

void last_delete()
{

    Node *srt = head;

    while (srt->link->link != NULL)
    {
        srt = srt->link;
    }

    srt->link = NULL;
}

int before_delete(ll p)
{
    Node *srt = head;

    int count=2;

    if (srt->link->info == p)
    {
        first_delete();
        return 0;
    }

    while (count != p)
    {
        count++;

        if (srt->link->link->link == NULL || srt->link->link == NULL || srt->link == NULL)
        {
            cout << "NOT FOUND." << endl;
            return 0;
        }

        else
            srt = srt->link;
    }

    srt->link = srt->link->link;
    return 0;
}

int after_delete(ll p)
{
    Node *srt = head;

    ll count=0;

    while (count != p)
    {
        count++;
        
        if (srt->link == NULL)
        {
            cout << "NOT FOUND." << endl;
            return 0;
        }

        else
            srt = srt->link;
    }

    if (srt->info == p && srt->link == NULL)
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    else
    {
        srt->link = srt->link->link;
        return 0;
    }
}

int given_delete(ll p)
{
    Node *srt = head;

    ll count=1;

    if (p==0)
    {
        first_delete();
        return 0;
    }

    while (count != p)
    {
        count++;

        if (srt->link != NULL)
            srt = srt->link;

        if (srt->link == NULL)
        {
            cout << "NOT FOUND" << endl;
            return 0;
        }
    }

    srt->link = srt->link->link;
    return 0;
}

int main()
{
    int a[]={0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++)
        creation(a[i]);

    cout << "Initial list: ";
    traverse();

    given_delete(4);
    //before_delete(4);
    //after_delete(1);
    traverse();
}