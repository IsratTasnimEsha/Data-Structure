// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void heapify(ll a[], ll n, ll i)
{
    ll largest = i, l_child = 2 * i + 1, r_child = 2 * i + 2;

    if (l_child <= n - 1 && a[l_child] < a[largest])
        largest = l_child;

    if (r_child <= n - 1 && a[r_child] < a[largest])
        largest = r_child;

    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void maxHeap(ll a[], ll n)
{
    for (ll i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
}

void deleteNode(ll a[], ll n)
{
    ll p=2;

    for (ll i = 0; i < n; i++)
        if (a[i] == p)
        {
            p = i;
            break;
        }

    swap(a[p], a[n - 1]);
    heapify(a, n - 1, p);
}

int main()
{
    ll n = 12;

    ll a[n] = {1, 2, 100, 3, 4, 200, 3000, 5000, 600, 700, 800, 500};

    maxHeap(a, n);
    deleteNode(a, n);

    for (ll i = 0; i < n - 1; i++)
        cout << a[i] << " ";
}