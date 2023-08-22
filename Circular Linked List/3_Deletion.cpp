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

void first_delete()
{
    if (head->link == head)
    {
        head = NULL;
        return;
    }

    head = head->link;
    temp->link = head;
}

void last_delete()
{
    Node *srt = head;

    while (srt->link->link != head)
        srt = srt->link;

    srt->link = head;
}

int before_delete(ll p)
{
    Node *srt = head;

    if (srt->info == p || srt == NULL || srt->link == head || (srt->link->info != p && srt->link->link == head))
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    if (srt->link->info == p)
    {
        first_delete();
        return 0;
    }

    while (srt->link->link->info != p)
    {
        if (srt->link->link->link == head || srt->link->link == head || srt->link == head)
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

    if (srt == NULL || srt->link == head || (srt->info == p && srt->link == head))
    {
        cout << "NOT FOUND." << endl;
        return 0;
    }

    while (srt->info != p)
    {
        if (srt->link == head)
        {
            cout << "NOT FOUND." << endl;
            return 0;
        }

        else
            srt = srt->link;
    }

    if (srt->info == p && srt->link == head)
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

    if (srt == NULL || (srt->info != p && srt->link == head))
    {
        cout << "NOT FOUND" << endl;
        return 0;
    }

    if (srt->info == p)
    {
        first_delete();
        return 0;
    }

    while (srt->link->info != p)
    {
        if (srt->link != head)
            srt = srt->link;

        if (srt->link == head)
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
    cout << "Total elements? ";
    ll n;
    cin >> n;

    cout << "Elements? ";

    for (ll i = 0; i < n; i++)
    {
        ll s;
        cin >> s;
        creation(s);
        // creation(a[i]);
    }

    cout << "List: ";
    traverse();

    while (1)
    {
        cout << "1. First Delete.\n2.Last Delete.\n3.Given Delete.\n4.Before Delete.\n5.After Delete.\n0. Exit." << endl;
        ll c;
        cin >> c;

        if (c == 1)
            first_delete();

        else if (c == 2)
            last_delete();

        else if (c == 3)
        {
            cout << "Element you want to delete? ";
            ll d;
            cin >> d;
            given_delete(d);
        }

        else if (c == 4)
        {
            cout << "Element you want to delete before? ";
            ll d;
            cin >> d;
            before_delete(d);
        }

        else if (c == 5)
        {
            cout << "Element you want to delete? ";
            ll d;
            cin >> d;
            after_delete(d);
        }

        else
            return 0;

        cout << "New list: ";
        traverse();
    }
}