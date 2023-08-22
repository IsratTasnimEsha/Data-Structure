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

ll lin_srch(nd **hd, ll p)
{
    nd *sr=*hd;
    while(sr!=NULL)
    {       
        if(sr->d==p)
        {
            cout<<"Found"<<endl;
            return 0;
        }
        sr=sr->nx;
    }
    cout<<"No"<<endl;
    return 0;
}

nd* mid(nd *l, nd *h)
{
    nd *sg=l;
    nd *dl=l;
    while(dl->nx!=h && dl->nx->nx!=h)
    {
        sg=sg->nx;
        dl=dl->nx->nx;
    }
    return sg;
}

ll bin_srch(nd **hd, ll p)
{
    nd *l=head, *h=NULL;
    while(l!=h)
    {
        nd *md=mid(l, h);
        if(md->d==p)
        {
            cout<<"Found"<<endl;
            return 0;
        }
        else if(p>md->d) l=md->nx;
        else h=md;
    }
    cout<<"No"<<endl;
    return 0;
}

int main()
{
    ll a[]={0, 1, 2, 3, 4, 5};
    
    for(ll i=0; i<6; i++) create(&head, a[i]);

    //lin_srch(&head, 5);
    bin_srch(&head, 0);
}