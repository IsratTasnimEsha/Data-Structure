// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class nd
{
public:
    ll d;
    nd *nx;
} * head, *tmp;

void create(nd **hd, ll m)
{
    nd *p = new nd();
    p->d = m;
    p->nx = NULL;
    if (*hd == NULL)
    {
        *hd = p;
        tmp = p;
    }
    tmp->nx = p;
    tmp = tmp->nx;
}

void f_in(nd **hd, ll m)
{
    nd *p = new nd();
    p->d = m;

    p->nx = *hd;
    *hd = p;
}

void l_in(nd **hd, ll m)
{
    nd *p = new nd();
    p->d = m;
    nd *sr = *hd;
    while (sr->nx != NULL)
        sr = sr->nx;
    sr->nx = p;
    p->nx = NULL;
}

ll b_in(nd **hd, ll q, ll m)
{
    nd *p = new nd();
    p->d = m;

    if ((*hd)->d == q)
    {
        f_in(&(*hd), m);
        return 0;
    }

    nd *sr1, *sr2;
    sr1 = *hd;
    sr2 = (*hd)->nx;

    while (sr2->d != q)
    {
        if (sr2->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
    }

    sr1->nx = p;
    p->nx = sr2;
    return 0;
}

ll a_in(nd **hd, ll q, ll m)
{
    nd *p = new nd();
    p->d = m;

    nd *sr1, *sr2;
    sr1 = *hd;
    sr2 = (*hd)->nx;

    while (sr1->d != q)
    {
        if (sr1->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
    }

    sr1->nx = p;
    p->nx = sr2;
    return 0;
}

ll b_p_in(nd **hd, ll k, ll m)
{
    if (k == 1)
    {
        f_in(&(*hd), m);
        return 0;
    }

    nd *p = new nd();
    p->d = m;

    nd *sr1, *sr2;
    sr1 = *hd;
    sr2 = (*hd)->nx;

    for(ll i=0; i<k-2; i++)
    {
        if (sr1->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
    }

    sr1->nx = p;
    p->nx = sr2;
    return 0;
}

ll g_p_in(nd **hd, ll k, ll m)
{
    if (k == 0)
    {
        f_in(&(*hd), m);
        return 0;
    }

    nd *p = new nd();
    p->d = m;

    nd *sr1, *sr2;
    sr1 = *hd;
    sr2 = (*hd)->nx;

    for (ll i = 0; i < k - 1; i++)
    {
        sr1 = sr1->nx;
        sr2 = sr2->nx;
    }

    sr1->nx = p;
    p->nx = sr2;
    return 0;
}

ll a_p_in(nd **hd, ll k, ll m)
{
    nd *p = new nd();
    p->d = m;

    nd *sr1, *sr2;
    sr1 = *hd;
    sr2 = (*hd)->nx;

    for (ll i = 0; i < k; i++)
    {
        sr1 = sr1->nx;
        sr2 = sr2->nx;
    }

    sr1->nx = p;
    p->nx = sr2;
    return 0;
}

void f_del(nd **hd)
{
    *hd = (*hd)->nx;
}

void l_del(nd **hd)
{
    nd *sr = *hd;
    while (sr->nx->nx != NULL)
        sr = sr->nx;
    sr->nx = NULL;
}

ll b_del(nd **hd, ll q)
{
    if ((*hd)->nx->d == q)
    {
        f_del(&(*hd));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    while (sr3->d != q)
    {
        if (sr3->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

ll g_del(nd **hd, ll q)
{
    if ((*hd)->d == q)
    {
        f_del(&(*hd));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    while (sr2->d != q)
    {
        if (sr2->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

ll a_del(nd **hd, ll q)
{
    nd *sr1, *sr2, *sr3;

    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    while (sr1->d != q)
    {
        if (sr2->nx == NULL)
        {
            cout << "NO" << endl;
            return 0;
        }
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

ll b_p_del(nd **hd, ll k)
{
    if (k == 1)
    {
        f_del(&(*hd));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    for (ll i = 0; i < k - 2; i++)
    {
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

ll g_p_del(nd **hd, ll k)
{
    if (k == 0)
    {
        f_del(&(*hd));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    for (ll i = 0; i < k - 1; i++)
    {
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

ll a_p_del(nd **hd, ll k)
{
    nd *sr1, *sr2, *sr3;

    sr1 = *hd;
    sr2 = (*hd)->nx;
    sr3 = (*hd)->nx->nx;

    for (ll i = 0; i < k; i++)
    {
        sr1 = sr1->nx;
        sr2 = sr2->nx;
        sr3 = sr3->nx;
    }

    sr1->nx = sr3;
    return 0;
}

void rev(nd **hd)
{
    nd *cr = *hd, *pr = NULL, *nxt = NULL;
    while (cr != NULL)
    {
        nxt = cr->nx;
        cr->nx = pr;

        pr = cr;
        cr = nxt;
    }
    *hd = pr;
}

void traverse(nd **hd)
{
    nd *sr = *hd;
    while (sr != NULL)
    {
        cout << sr->d << " ";
        sr = sr->nx;
    }
}

int main()
{
    ll a[] = {0, 1, 2, 3, 4, 5};

    for (ll i = 0; i < 6; i++)
        create(&head, a[i]);

    // f_in(&head, 0);
    // l_in(&head, 9);
    // b_in(&head, 2, 7);
    // a_in(&head, 6, 7);

    // f_del(&head);
    // l_del(&head);
    // b_del(&head, 1);
    // g_del(&head, 1);
    // a_del(&head, 6);

    // g_p_in(&head, 3, 90);
    // a_p_in(&head, 5, 90);
    b_p_in(&head, 3, 90);

    // b_p_del(&head, 4);
    // g_p_del(&head, 4);
    // a_p_del(&head, 3);

    // rev(&head);
    traverse(&head);
}