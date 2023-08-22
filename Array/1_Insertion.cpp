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

    ll k=2, m=10;
    n++;

    //..............................................................Unordered..............................................................

    /*
    a[n-1]=a[k];
    a[k]=m;
    
    for(ll i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    */
    
    //..............................................................Ordered..............................................................

    for(ll i=n-2; i>=k; i--) a[i+1]=a[i];
    a[k]=m;

    for(ll i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;  
}