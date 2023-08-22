// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll fibonacci(ll n)
{
    if (n == 1 || n == 0)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    /*
    ll n = 10;

    ll feb1 = 0, feb2 = 1, feb3 = 0;
    cout << feb1 << " " << feb2 << " ";

    n -= 2;

    for (ll i = 0; i < n; i++)
    {
        feb3 = feb1 + feb2;
        feb1 = feb2;
        feb2 = feb3;
        cout << feb3 << " ";
    }
    cout << endl;
    */

    ll m = 10;

    for (ll i = 0; i < m; i++)
        cout << fibonacci(i) << " ";
}