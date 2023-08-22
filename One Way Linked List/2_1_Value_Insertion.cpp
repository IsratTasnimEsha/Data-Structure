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
    if (head == NULL || (head->info != q && head->next == NULL))
    {
        cout << "NOT FOUND" << endl;
        return;
    }

    if (head->info == q)
    {
        first_insert(n);
        return;
    }

    Node *srt = head;
    Node *srt2 = head->next;

    while (srt2->info != q)
    {
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
    if (head == NULL)
    {
        cout << "NOT FOUND" << endl;
        return;
    }

    Node *srt = head;
    Node *srt2 = head->next;

    while (srt->info != q)
    {
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