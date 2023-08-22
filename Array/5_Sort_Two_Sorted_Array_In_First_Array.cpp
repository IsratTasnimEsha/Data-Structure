// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void insert(ll a[], ll n, ll k, ll p)
{
    n++;

    for (ll i = n - 2; i >= k; i--)
        a[i + 1] = a[i];

    a[k] = p;
}

int main()
{
    ll n = 6, m = 5, i = 0, j = 0;

    ll a[n] = {1, 2, 4, 7, 20, 22}, b[m] = {2, 4, 6, 8, 99};

    while (i < n || j < m)
    {
        if (a[i] > b[j])
        {
            insert(a, n + j, i, b[j]);
            j++;
        }

        i++;
    }

    n += m;

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
}