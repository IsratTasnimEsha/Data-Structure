// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void deleteMaxHeap(ll a[], ll n)
{
    a[0]=a[n-1];

    n--;

    ll i=0;

    while(i<n-1)
    {
        ll l_child=2*i+1;
        ll r_child=2*i+2;

        if(a[i]<a[l_child] && a[l_child]>=a[r_child])
        {
            swap(a[i], a[l_child]);
            i=l_child;
        }

        else if(a[i]<a[r_child] && a[r_child]>a[l_child])
        {
            swap(a[i], a[r_child]);
            i=r_child;
        }
        
        else break;
    }
}

int main()
{
    ll n=7;

    ll a[n]={10, 5, 8, 3, 2, 6, 1};

    deleteMaxHeap(a, n);
    
    for(ll i=0; i<n-1; i++) cout<<a[i]<<" ";
}