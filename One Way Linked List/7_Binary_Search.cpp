// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *link;
} * head, *temp;

void Creation(int n)
{
    Node *p = new Node();
    p->info = n;
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

Node *Middle(Node *low, Node *high)
{
    Node *sngl = low;
    Node *dbl = low;

    while (dbl->link != high && dbl->link->link != high)
    {
        sngl = sngl->link;
        dbl = dbl->link->link;
    }

    return sngl;
}

int Binary_Search(int n)
{
    Node *low = head;
    Node *high = NULL;

    int count = 0;

    while (low != high)
    {
        count++;

        Node *mid = Middle(low, high);

        if (mid->info == n)
        {
            cout<<"FOUND :)"<<endl;
            cout << "Steps: " << count << endl;
            return 0;
        }

        else if (mid->info < n)
            low = mid->link;

        else
            high = mid;
    }

    return -1;
}

void Traverse()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->info << " ";
        temp = temp->link;
    }

    cout << endl;
}

int main()
{
    int a[]={8, 9, 10, 11};

    for (int i = 0; i < 4; i++)
    {
        //int n;
        //cin >> n;
        Creation(a[i]);
    }

    Traverse();

    int m=7;
    cout<<"Search "<<m<<endl;

    if (Binary_Search(m) == -1)
        cout << "NOT FOUND :/" << endl;
}