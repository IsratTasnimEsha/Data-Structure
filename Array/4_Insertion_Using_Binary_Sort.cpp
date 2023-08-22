// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

ll Search(ll a[], ll n, ll p)
{
    ll low = 0, high = n - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (p >= a[mid] && p <= a[mid + 1])
            return mid + 1;

        else if (p < a[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    ll n;
    cout << "Total elements? ";
    cin >> n;

    ll a[n + 5];
    cout << "Elements? ";
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll p;
    cout << "Element you want to insert? ";
    cin >> p;

    ll srch = Search(a, n, p);

    n++;

    for (ll i = n - 2; i >= srch; i--)
        a[i + 1] = a[i];

    a[srch] = p;

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
}