//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define print for(long long i=0; i<n; i++) cout<<a[i]<<" "
#define by cout<<endl

ll b_search(ll a[], ll n, ll p)
{
    ll l=0, h=n-1;
    while(l<=h)
    {
        ll m=(l+h)/2;
        if(a[m]==p) return m;
        else if(p>a[m]) l=m+1;
        else h=m-1;
    }
    return -1;
}
int main()
{
    ll n=6;
    ll a[n]={1, 2, 4, 5, 6, 7};
    cout<<b_search(a, n, 1);
}