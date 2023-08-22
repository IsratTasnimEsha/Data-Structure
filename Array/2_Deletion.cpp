//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

int main()
{
    ll a[100]={1, 2, 3, 4, 5};
    ll n=5;

    ll k=2;

    //..............................................................Unordered..............................................................

    /*
    a[k]=m;
    n--;
    
    for(ll i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    */
    
    //..............................................................Ordered..............................................................

    for(ll i=k; i<n-1; i++) a[i]=a[i+1];

    n--;

    for(ll i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
}