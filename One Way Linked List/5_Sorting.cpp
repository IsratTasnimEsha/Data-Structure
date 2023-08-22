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
        {
            cout << srt->info << " ";
            srt = srt->link;
        }
    }

    cout << endl;
}

void swap(Node *srt1, Node *srt2)
{
    ll p = srt1->info;
    srt1->info = srt2->info;
    srt2->info = p;
}

void BubbleSort()
{
    Node *srt1 = head;

    while (srt1->link != NULL)
    {
        Node *srt2 = head;
        ll isSorted = 1;

        while (srt2->link != NULL)
        {
            if (srt2->info > srt2->link->info)
            {
                swap(srt2, srt2->link);
                isSorted = 0;
            }
            srt2 = srt2->link;
        }
        srt1 = srt1->link;

        if (isSorted)
            break;
    }
}

int main()
{
    ll a[] = {33, 55, 7, 99, 10};

    for (ll i = 0; i < 5; i++)
    {
        creation(a[i]);
    }

    BubbleSort();
    traverse();
}