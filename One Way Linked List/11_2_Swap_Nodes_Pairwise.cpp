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
    ll countX = 0, countY = 0;

    if (x == y)
        return;

    Node *currentX = head, *currentY = head, *prevX = NULL, *prevY = NULL;

    while (countX != x)
    {
        countX++;
        prevX = currentX;
        currentX = currentX->link;
    }

    while (countY != y)
    {
        countY++;
        prevY = currentY;
        currentY = currentY->link;
    }

    if (currentX == NULL || currentY == NULL)
        return;

    if (prevX == NULL)
        head = currentY;
    else
        prevX->link = currentY;

    if (prevY == NULL)
        head = currentX;
    else
        prevY->link = currentX;

    Node *temp = currentY->link;
    currentY->link = currentX->link;
    currentX->link = temp;
}

void swapPairwise()
{
    Node *srt = head;
    ll count = 0;

    while (1)
    {
        swapNodes(count, count + 1);

        count += 2;

        if (srt == NULL || srt->link == NULL)
            break;

        srt = srt->link->link;
    }
}

int main()
{
    ll a[] = {9, 4, 2, 0, 1, 5, 8, 7, 3, 6, 9};

    for (ll i = 0; i < 11; i++)
        Creation(a[i]);

    swapPairwise();

    Traverse();
}