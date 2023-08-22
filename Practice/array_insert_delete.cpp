//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define print for(long long i=0; i<n; i++) cout<<a[i]<<" "
#define by cout<<endl

int main()
{
    ll n=6;
    ll a[n]={1, 2, 4, 5, 6, 7};
    ll k=2;
    n++;
    for(ll i=n-2; i>=k; i--) a[i+1]=a[i];
    a[k]=3;
    print; by;
    for(ll i=k; i<n; i++) a[i]=a[i+1];
    n--;
    print;
}