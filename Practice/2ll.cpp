//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class nd
{
public:
    ll d;
    nd *nx, *pr;
} *head, *tail;

void create(nd **hd, nd **tl, ll m)
{
    nd *p=new nd();
    p->d=m;
    p->nx=NULL;
    p->pr=NULL;

    if(*hd==NULL)
    {
        *hd=p;
        *tl=p;
    }

    (*tl)->nx=p;
    p->pr=*tl;
    *tl=(*tl)->nx;
}

void f_in(nd **hd, nd **tl, ll m)
{
    nd *p=new nd();
    p->d=m;
    
    p->pr=NULL;
    p->nx=*hd;

    (*hd)->pr=p;

    *hd=p;
}

void l_in(nd **hd, nd **tl, ll m)
{
    nd *p=new nd();
    p->d=m;

    (*tl)->nx=p;

    p->pr=*tl;
    p->nx=NULL;

    *tl=p;
}

ll b_in(nd **hd, nd **tl, ll q, ll m)
{
    nd *p=new nd();
    p->d=m;

    if((*hd)->d==q)
    {
        f_in(&(*hd), &(*tl), m);
        return 0;
    }

    nd *sr1, *sr2;
    sr1=*hd;
    sr2=(*hd)->nx;

    while(sr2->d!=q)
    {
        if(sr2->nx==NULL)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        sr1=sr1->nx;
        sr2=sr2->nx;
    }

    sr1->nx=p;
    p->pr=sr1;

    p->nx=sr2;
    sr2->pr=p;

    return 0;
}

ll a_in(nd **hd, nd **tl, ll q, ll m)
{
    nd *p=new nd();
    p->d=m;

    if(tail->d==q)
    {
        l_in(&(*hd), &(*tl), m);
        return 0;
    }

    nd *sr1, *sr2;
    sr1=*hd;
    sr2=(*hd)->nx;

    while(sr1->d!=q)
    {
        if(sr1->nx==NULL)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        sr1=sr1->nx;
        sr2=sr2->nx;
    }

    sr1->nx=p;
    p->pr=sr1;

    p->nx=sr2;
    sr2->pr=p;

    return 0;
}

void f_del(nd **hd, nd **tl)
{
    *hd=(*hd)->nx;
    (*hd)->pr=NULL;
}

void l_del(nd **hd,  nd **tl)
{
    *tl=(*tl)->pr;
    (*tl)->nx=NULL;    
}

ll b_del(nd **hd,  nd **tl, ll q)
{
    if((*hd)->nx->d==q)
    {
        f_del(&(*hd), &(*tl));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1=*hd;
    sr2=(*hd)->nx;
    sr3=(*hd)->nx->nx;

    while(sr3->d!=q)
    {
        if(sr3->nx==NULL)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        sr1=sr1->nx;
        sr2=sr2->nx;
        sr3=sr3->nx;
    }

    sr1->nx=sr3;
    sr3->pr=sr1;

    return 0;
}

ll g_del(nd **hd,  nd **tl, ll q)
{
    if((*hd)->d==q)
    {
        f_del(&(*hd), &(*tl));
        return 0;
    }

    if((*tl)->d==q)
    {
        l_del(&(*hd), &(*tl));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1=*hd;
    sr2=(*hd)->nx;
    sr3=(*hd)->nx->nx;

    while(sr2->d!=q)
    {
        if(sr2->nx==NULL)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        sr1=sr1->nx;
        sr2=sr2->nx;
        sr3=sr3->nx;
    }

    sr1->nx=sr3;
    sr3->pr=sr1;

    return 0;
}

ll a_del(nd **hd,  nd **tl, ll q)
{
    if((*tl)->pr->d==q)
    {
        l_del(&(*hd), &(*tl));
        return 0;
    }

    nd *sr1, *sr2, *sr3;
    sr1=*hd;
    sr2=(*hd)->nx;
    sr3=(*hd)->nx->nx;

    while(sr1->d!=q)
    {
        if(sr2->nx==NULL)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        sr1=sr1->nx;
        sr2=sr2->nx;
        sr3=sr3->nx;
    }

    sr1->nx=sr3;
    sr3->pr=sr1;

    return 0;
}

void traverse(nd **hd)
{
    cout<<"trav:\t";
    nd *sr=*hd;
    while(sr!=NULL)
    {       
        cout<<sr->d<<" ";
        sr=sr->nx;
    }
    cout<<endl;
}

void r_traverse(nd **tl)
{
    cout<<"r_trav:\t";
    nd *sr=*tl;
    while(sr!=NULL)
    {       
        cout<<sr->d<<" ";
        sr=sr->pr;
    }
    cout<<endl;
}

int main()
{
    ll a[]={1, 2, 3, 4, 5, 6};
    
    for(ll i=0; i<6; i++) create(&head, &tail, a[i]);

    //f_in(&head, &tail, 0);
    //l_in(&head, &tail, 9);
    //b_in(&head, &tail, 66, 7);
    //a_in(&head, &tail, 6, 7);

    //f_del(&head, &tail);
    //l_del(&head, &tail);
    //b_del(&head, &tail, 5);
    //g_del(&head, &tail, 3);
    //a_del(&head, &tail, 3);

    head->pr=NULL;
    tail->nx=NULL;
    
    traverse(&head);
    r_traverse(&tail);
}