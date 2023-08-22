// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

/*
Given array: 8 0 7 1 3

Step 1: Searching the minimum value
0<8 and 0<7, 0<1, 0<3 too. so 0 is the smallest.
so, swap 8 and 0
Therefore, 0 8 7 1 3

Step 2: Searching the second minimum value (0 is fixed)
8>7, so 7 is smaller, then 7<1. so 1 is smaller than 7, and 1 is smaller than 3 too.
so, swap 8 and 1
Therefore, 0 1 7 8 3

Step 3: Searching the third minimum value ([0, 1] is fixed)
7<8 but 7>3, so 3 is smaller.
so, swap 7 and 3
Therefore, 0 1 3 8 7

Step 4: Searching the forth minimum value ([0, 1, 3] is fixed)
8>7 so 7 is smaller.
so, swap 7 and 8
Therefore, 0 1 3 7 8
and 8 is the greatest.

therefore, total steps= (5-1) = (n-1)
and total times = 1+2+3+4 = 1+2+3+....+(n-1)= (n*(n-1))/2

#Not stable
#Not adaptive
#Best Case=Worst Case=O(n^2)
*/

void Selection_Sort(ll a[], ll n)
{
    for(ll i=0; i<n-1; i++)
        for(ll j=i+1; j<n; j++)
            if(a[j]<a[i]) swap(a[i], a[j]);
}

int main()
{
    ll a[]={5, 2, 7, 1, 5, 2, 6, 9, 0, 0};
    ll n = sizeof(a) / sizeof(ll);

    Selection_Sort(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}