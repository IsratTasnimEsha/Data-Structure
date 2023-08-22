// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Node
{
public:
    ll info;
    Node *prev, *next;
} * head, *tail;

void creation(ll m)
{
    Node *p = new Node();
    p->prev = NULL;
    p->info = m;
    p->next = NULL;

    if (head == NULL)
    {
        head = p;
        tail = p;
    }

    else
    {
        tail->next = p;
        p->prev = tail;
        tail = tail->next;
    }
}

void traverse()
{
    Node *srt = head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->next;
    }

    cout << endl;
}

void reverse_traverse()
{
    Node *srt = tail;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->prev;
    }

    cout << endl
         << endl;
}

void first_insert(int m)
{
    if(head==NULL)
    {
        creation(m);
        return;
    }

    Node *p = new Node();
    p->info = m;
    
    p->prev = NULL;
    p->next = head;
    head->prev=p;

    head = p;
}

void last_insert(int m)
{
    if(head==NULL)
    {
        creation(m);
        return;
    }
    
    Node *p = new Node();
    p->info = m;

    tail->next = p;
    p->prev = tail;
    p->next = NULL;

    tail = p;
}

int before_insert(int q, int m)
{
    Node *p = new Node();
    p->info = m;

    Node *srt1 = head;
    Node *srt2 = head->next;

    if (srt1->info == q)
    {
        first_insert(m);
        return 1;
    }

    while (srt2->info != q)
    {
        if (srt2->next == NULL)
        {
            cout << "NOT FOUND" << endl;
            return 0;
        }

        srt1 = srt1->next;
        srt2 = srt2->next;
    }
    srt1->next = p;
    p->prev = srt1;

    p->next = srt2;
    srt2->prev = p;

    return 1;
}

void after_insert(int q, int m)
{
    if (head == NULL)
    {
        cout << "NOT FOUND" << endl;
        return;
    }

    Node *p = new Node();
    p->info = m;

    Node *srt1 = head;
    Node *srt2 = head->next;

    if (tail->info == q)
    {
        last_insert(m);
        return;
    }

    while (srt1->info != q)
    {
        if (srt1->next == NULL)
        {
            cout << "NOT FOUND" << endl;
            return;
        }

        srt1 = srt1->next;
        srt2 = srt2->next;
    }
    srt1->next = p;
    p->prev = srt1;

    p->next = srt2;
    srt2->prev = p;

    return;
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
            cin>>ins;
            first_insert(ins);
        }

        if (choice == 2)
        {
            cout << "Element you want to insert last? ";
            int ins;
            cin>>ins;
            last_insert(ins);
        }

        if (choice == 3)
        {
            cout << "Element you want to insert before? ";
            int item;
            cin>>item;
            cout << "Element you want to insert before "<<item<<"? ";
            int ins;
            cin>>ins;
            before_insert(item, ins);
        }

        if (choice == 4)
        {
            cout << "Element you want to insert after? ";
            int item;
            cin>>item;
            cout << "Element you want to insert after "<<item<<"? ";
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