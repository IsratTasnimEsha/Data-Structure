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

int linear_search(int n)
{
    Node *temp = head;
    int count = 0;

    if (temp->info == n)
        return 0;

    while (temp->info != n)
    {
        if (temp->link == NULL)
            return -1;

        count++;
        temp = temp->link;
    }

    return count;
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
    int a[]={1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        //int n;
        //cin >> n;
        Creation(a[i]);
    }

    Traverse();

    if (linear_search(5) == -1)
        cout << "NOT FOUND" << endl;

    else
        cout << "Index: " << linear_search(44) << endl;
}