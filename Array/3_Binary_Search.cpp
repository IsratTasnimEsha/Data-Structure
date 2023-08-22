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

        if (p == a[mid])
            return mid;

        else if (p < a[mid])
            high = mid - 1;

        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    // ll a[] = {4, 1, 8, 0, 2, 6, 5, 9, 3, 7} can't be

    // should be sorted array
    ll a[] = {6, 14, 26, 38, 45, 53, 65, 73, 83, 96, 106};

    ll p = 6;
    ll n = 11;

    ll i = Search(a, n, 6); 
    cout << i << endl;

    i = Search(a, n, 14); 
    cout << i << endl;

    i = Search(a, n, 26); 
    cout << i << endl;

    i = Search(a, n, 38); 
    cout << i << endl;

    i = Search(a, n, 45); 
    cout << i << endl;

    i = Search(a, n, 53); 
    cout << i << endl;

    i = Search(a, n, 65); 
    cout << i << endl;

    i = Search(a, n, 73); 
    cout << i << endl;

    i = Search(a, n, 83); 
    cout << i << endl;

    i = Search(a, n, 96); 
    cout << i << endl;

    i = Search(a, n, 106); 
    cout << i << endl;
}