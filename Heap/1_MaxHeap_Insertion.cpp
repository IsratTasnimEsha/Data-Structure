// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void insertMaxHeap(ll a[], ll n, ll p)
{
    n++;
    a[n-1]=p;
    ll i=n-1;
    
    while(i>0)
    {
        ll parent=(i-1)/2;
        if(a[i]>a[parent])
        {
            swap(a[parent], a[i]);
            i=parent;
        }
        else break;
    }
}
int main()
{
    ll n=9, p=20;

    ll a[n]={70, 50, 40, 45, 35, 39, 16, 10, 9};

    insertMaxHeap(a, n, p);
    
    for(ll i=0; i<n+1; i++) cout<<a[i]<<" ";
}