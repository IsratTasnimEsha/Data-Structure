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
Node *head, *temp;

void Creation(ll m)
{

    // creating new node
    Node *p = new Node();
    p->info = m;
    p->link = NULL;

    if (head == NULL)
    {
        // head points to new node p
        head = p;
        // head points to new node p. It will be changable and will be used to link new nodes.
        temp = p;
    }

    else
    {
        // link to new node
        temp->link = p;
        // points to next node
        temp = temp->link;
    }
}

void Traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->link;
    }
    cout << endl;
}

void swapNodes(ll x, ll y)
{
    Node *srtx1=head, *srtx2=head->link, *srtx3=head->link->link;
    int count=0;
    for(int i=0; i<x-1; i++)
    {
        count++;
        srtx1=srtx1->link;
        srtx2=srtx2->link;
        srtx3=srtx3->link;
    }
    srtx1->link=srtx3;

    Node *srty1=head, *srty2=head->link, *srty3=head->link->link;
    for(int i=0; i<y-2; i++)
    {
        srty1=srty1->link;
        srty2=srty2->link;
        srty3=srty3->link;
    }
    srty1->link=srtx2;
    srtx2->link=srty3;

    Node *srt1=head, *srt2=head->link;
    for(ll i=0; i<count; i++)
    {
        srt1=srt1->link;
        srt2=srt2->link;
    }
    srt1->link=srty2;
    srty2->link=srt2;
}

void First_two_swap()
{
    Node *srt1=head, *srt2=head->link;
    srt1->link=srt1->link->link;
    srt2->link=srt1;
    head=srt2;
}

int main()
{
    ll a[] = {00, 10, 20, 30, 40, 50, 60, 70, 80, 90};

    for (ll i = 0; i < 10; i++)
        Creation(a[i]);

    //swapNodes(3, 7);
    First_two_swap();

    Traverse();
}