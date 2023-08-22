//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class nd
{
public:
    ll d;
    nd *nx;
} *head1, *head2, *tmp;

void create(nd **hd, ll m)
{
    nd *p=new nd();
    p->d=m;
    p->nx=NULL;
    if(*hd==NULL)
    {
        *hd=p;
        tmp=p;
    }
    tmp->nx=p;
    tmp=tmp->nx;
}

void traverse(nd **hd)
{
    nd *sr=*hd;
    while(sr!=NULL)
    {       
        cout<<sr->d<<" ";
        sr=sr->nx;
    }
    cout<<endl;
}

void b_in(ll q, ll m)
{
    nd *p=new nd();
    p->d=m;
    if(head1->d==q)
    {
        p->nx=head1;
        head1=p;
    }
    else
    {
        nd *sr1, *sr2;
        sr1=head1;
        sr2=head1->nx;
        while(sr2->d!=q)
        {
            sr1=sr1->nx;
            sr2=sr2->nx;
        }
        sr1->nx=p;
        p->nx=sr2;
    }
}

ll merge()
{
    nd *hd1=head1;
    
    while(1)
    {
        while((hd1)->d>(head2)->d)
        {
            b_in(hd1->d, head2->d);
            if(head2->nx==NULL) return 0;
            head2=head2->nx;
        }
        if(hd1->nx==NULL) break;
        hd1=hd1->nx;
    }
    if(head2!=NULL)  hd1->nx=head2;
    return 0;
}

int main()
{
    ll a[]={0, 4, 7, 12, 29, 32}, b[]={3, 5, 9, 10, 23};

    for(ll i=0; i<6; i++) create(&head1, a[i]);
    for(ll i=0; i<5; i++) create(&head2, b[i]);

    merge();
    traverse(&head1);
}