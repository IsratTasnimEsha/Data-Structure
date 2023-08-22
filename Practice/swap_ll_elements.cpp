//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long

class nd
{
public:
    ll d;
    nd *nx;
} *head, *tmp;

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

void Swap(ll x, ll y)
{
    if(x==y) return;
    
    nd *crx=head, *cry=head, *prx=NULL, *pry=NULL;
    
    while(crx && crx->d!=x)
    {
        prx=crx;
        crx=crx->nx;
    }
    //prx={2}, crx={3}
    //crx->nx={4, 5, 6, 7, 8, 9}
    
    while(cry && cry->d!=y)
    {
        pry=cry;
        cry=cry->nx;
    }
    //pry={7}, cry={8}
    //cry->nx={9}

    
    //crx->nx={9}
    //cry->nx={4, 5, 6, 7, 8, 9}

    //crx={3, 9}
    //cry={8, 4, 5, 6, 7, 8, 9}

    if(crx==NULL || cry==NULL) return;
    
    if(prx!=NULL) prx->nx=cry; //prx={2, 8, 4, 5, 6, 7, 8, 9}
    else head=cry;

    if(pry!=NULL) pry->nx=crx; //pry={7, 3}
    else head=crx;

    nd *tmp=crx->nx;
    crx->nx=cry->nx;
    cry->nx=tmp;

    //
}

int main()
{
    ll a[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for(ll i=0; i<10; i++) create(&head, a[i]);
    
    Swap(3, 8);
    traverse(&head);
}