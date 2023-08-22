// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void heapify(ll a[], ll n, ll i)
{
    ll largest = i, l_child = 2 * i + 1, r_child = 2 * i + 2;

    if (l_child <= n - 1 && a[l_child] > a[largest])
        largest = l_child;

    if (r_child <= n - 1 && a[r_child] > a[largest])
        largest = r_child;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(ll a[], ll n)
{
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
        
    for (ll i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main()
{
    ll n = 7;

    ll a[n] = {15, 5, 20, 1, 17, 10, 30};

    heapSort(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";
}