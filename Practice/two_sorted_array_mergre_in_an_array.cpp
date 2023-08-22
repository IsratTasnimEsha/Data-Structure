//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define print for(long long i=0; i<n; i++) cout<<a[i]<<" "
#define by cout<<endl

void insert(ll a[], ll n, ll k, ll p)
{
    n++;
    for(ll i=n-2; i>=k; i--) a[i+1]=a[i];
    a[k]=p;
}
int main()
{
    ll n=6, m=5;
    ll a[n]={1, 2, 5, 7, 20, 22}, b[m]={3, 4, 6, 8, 9};
    for(ll i=0, j=0; i<n, j<m; i++) if(a[i]>b[j]) insert(a, n+j, i, b[j++]);
    n+=m;
    print; by;
}