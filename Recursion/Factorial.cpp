// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll factorial(ll n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    /*
    ll n = 5, fact = 1;

    for (ll i = 1; i <= n; i++)
        fact *= i;

    cout << fact << endl;
    */
   
   ll m=5;
    cout << factorial(m) << endl;
}
