//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class nd
{
public:
    ll d;
    nd *nx;
} *head, *head1, *head2, *tmp;

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

void merge(nd **hd1, nd **hd2)
{
    if((*hd1)->d<=(*hd2)->d)
    {
        head=*hd1;
        *hd1=(*hd1)->nx;
    }
    if((*hd1)->d>(*hd2)->d)
    {
        head=*hd2;
        *hd2=(*hd2)->nx;
    }
    nd *hd=head;
    while(*hd1 && *hd2)
    {
        if((*hd1)->d<(*hd2)->d)
        {
            hd->nx=*hd1;
            hd=hd->nx;
            *hd1=(*hd1)->nx;
        }
        else
        {
            hd->nx=*hd2;
            hd=hd->nx;
            *hd2=(*hd2)->nx;
        }
    }
    if(*hd1!=NULL) hd->nx=*hd1;
    if(*hd2!=NULL) hd->nx=*hd2;
}

int main()
{
    ll a[]={0, 1, 4, 7, 111, 200}, b[]={2, 5, 6, 9, 100};

    for(ll i=0; i<6; i++) create(&head1, a[i]);
    for(ll i=0; i<5; i++) create(&head2, b[i]);

    merge(&head1, &head2);
    traverse(&head);
}