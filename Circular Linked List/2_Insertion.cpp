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

void creation(ll m)
{
    Node *p = new Node();
    p->info = m;
    p->link = head;

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
    temp->link=head;
}

void traverse()
{
    Node *srt = head;

    while (srt->link != head)
    {
        cout << srt->info << " ";
        srt = srt->link;
    }

    if (srt->link == head)
        cout << srt->info << endl;
}

void first_insert(int n)
{
    Node *p = new Node();
    p->info = n;

    temp->link = p;
    p->link = head;

    head = p;
}

void last_insert(int n)
{
    Node *p = new Node();
    p->info = n;

    temp->link = p;
    p->link = head;
}

void before_insert(int q, int n)
{
    if (head->info == q)
        first_insert(n);

    else
    {
        Node *srt = head;
        Node *srt2 = head->link;

        while (srt2->info != q)
        {
            if (srt2->link == head)
            {
                cout << "NOT FOUND" << endl;
                return;
            }

            srt = srt->link;
            srt2 = srt2->link;
        }

        Node *p = new Node();
        p->info = n;

        srt->link = p;
        p->link = srt2;
    }
}

void after_insert(int q, int n)
{
    Node *srt = head;
    Node *srt2 = head->link;

    while (srt->info != q)
    {
        if (srt->link == head)
        {
            cout << "NOT FOUND" << endl;
            return;
        }

        else
        {
            srt = srt->link;
            srt2 = srt2->link;
        }
    }

    Node *p = new Node();
    p->info = n;

    srt->link = p;
    p->link = srt2;
}

int main()
{
    int n, m;
    cout << "No. of elements? ";
    cin >> n;

    cout << "Elements? ";
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        creation(m);
    }

    cout << "Initial list: ";
    traverse();

    while (1)
    {
        cout << "1. First Insert.\n2. Last Insert.\n3. Before Insert.\n4. After Insert.\n0. Exit." << endl;
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Element you want to insert first? ";
            int ins;
            cin >> ins;
            first_insert(ins);
        }

        if (choice == 2)
        {
            cout << "Element you want to insert last? ";
            int ins;
            cin >> ins;
            last_insert(ins);
        }

        if (choice == 3)
        {
            cout << "Element you want to insert before? ";
            int item;
            cin >> item;
            cout << "Element you want to insert before " << item << "? ";
            int ins;
            cin >> ins;
            before_insert(item, ins);
        }

        if (choice == 4)
        {
            cout << "Element you want to insert after? ";
            int item;
            cin >> item;
            cout << "Element you want to insert after " << item << "? ";
            int ins;
            cin >> ins;
            after_insert(item, ins);
        }

        cout << "New List: ";
        traverse();

        if (choice == 0)
            return 0;
    }
}