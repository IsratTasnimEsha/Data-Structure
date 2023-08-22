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

void first_delete()
{
    head = head->next;
    head->prev = NULL;
}

void last_delete()
{
    tail = tail->prev;
    tail->next = NULL;
}

int before_delete(ll p)
{
    Node *srt = head;

    if (srt->info == p || srt == NULL || srt->next == NULL || (srt->next->info != p && srt->next->next == NULL))
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    if (srt->next->info == p)
    {
        first_delete();
        return 0;
    }

    while (srt->next->next->info != p)
    {
        if (srt->next->next->next == NULL || srt->next->next == NULL || srt->next == NULL)
        {
            cout << "NOT FOUND." << endl;
            return 0;
        }

        else
            srt = srt->next;
    }

    Node *srt2 = srt->next->next;
    srt->next = srt2;
    srt2->prev = srt;
    return 0;
}

int after_delete(ll p)
{
    Node *srt = head;

    if (srt == NULL || srt->next==NULL || (srt->info == p && srt->next == NULL))
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    if (tail->prev->info == p)
    {
        last_delete();
        return 0;
    }

    while (srt->info != p)
    {
        if (srt->next == NULL)
        {
            cout << "NOT FOUND." << endl;
            return 0;
        }

        else
            srt = srt->next;
    }

    if (srt->info == p && srt->next == NULL)
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    else
    {
        Node *srt2 = srt->next->next;
        srt->next = srt2;
        srt2->prev = srt;
        return 0;
    }
}

int given_delete(ll p)
{
    Node *srt = head;

    if (srt == NULL || (srt->info != p && srt->next == NULL))
    {
        cout << "NOT FOUND" << endl;
        return 0;
    }

    if (srt->info == p)
    {
        first_delete();
        return 0;
    }

    if (tail->info == p)
    {
        last_delete();
        return 0;
    }

    while (srt->next->info != p)
    {
        if (srt->next != NULL)
            srt = srt->next;

        if (srt->next == NULL)
        {
            cout << "NOT FOUND" << endl;
            return 0;
        }
    }

    Node *srt2 = srt->next->next;
    srt->next = srt2;
    srt2->prev = srt;
    return 0;
}

int main()
{
    ll n, m;
    cout << "No. of elements? ";
    cin >> n;

    cout << "Elements? ";
    for (ll i = 0; i < n; i++)
    {
        cin >> m;
        creation(m);
    }

    cout << "Initial list: ";
    traverse();
    cout << "Initial list reverse: ";
    reverse_traverse();

    while (1)
    {
        cout << "1. First Delete.\n2. Last Delete.\n3. Given Delete.\n4. Before Delete.\n5. After Delete.\n0. Exit." << endl;
        ll choice;
        cin >> choice;

        if (choice == 1)
            first_delete();

        if (choice == 2)
            last_delete();

        if (choice == 3)
        {
            cout << "Element you want to delete? ";
            ll del;
            cin >> del;
            given_delete(del);
        }

        if (choice == 4)
        {
            cout << "Element you want to delete before? ";
            ll del;
            cin >> del;
            before_delete(del);
        }

        if (choice == 5)
        {
            cout << "Element you want to delete after? ";
            ll del;
            cin >> del;
            after_delete(del);
        }

        cout << "New List: ";
        traverse();
        cout << "New list reverse: ";
        reverse_traverse();

        if (choice == 0)
            return 0;
    }
}