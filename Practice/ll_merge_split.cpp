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

void merge(nd **hd1, nd **hd2)
{
    nd *sr=*hd1;
    while(sr->nx!=NULL) sr=sr->nx;
    sr->nx=*hd2;    
}

nd* split(nd **hd1, ll k)
{
    nd *sr=*hd1, *hd2;
    ll cnt=1;
    while(cnt!=k)
    {
        cnt++;
        sr=sr->nx;
    }
    hd2=sr->nx;
    sr->nx=NULL;
    return hd2;
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

int main()
{
    ll a[]={0, 1, 2, 3, 4, 5}, b[]={6, 7, 8, 9, 10};

    for(ll i=0; i<6; i++) create(&head1, a[i]);
    for(ll i=0; i<5; i++) create(&head2, b[i]);

    merge(&head1, &head2);
    head2=split(&head1, 5);

    traverse(&head1);
    traverse(&head2);
}