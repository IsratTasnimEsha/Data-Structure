#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll fibonacci(ll n)
{
    if(n<=1) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{
    ll n=9;
    cout<<fibonacci(n);
}