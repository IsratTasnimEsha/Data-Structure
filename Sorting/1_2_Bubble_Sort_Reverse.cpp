// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

/*
given array: 7 4 5 9 2

1st step: Searching the minimum value
7 4 5 9 2 (comparing index 0 and 1)
7 5 4 9 2 (comparing index 1 and 2)
7 5 9 4 2 (comparing index 2 and 3)
7 5 9 4 2 (comparing index 3 and 4)
so, 2 is the smallest number.

2nd step: Searching the second minimum value (2 is fixed)
7 5 9 4 2 (comparing index 0 and 1)
7 9 5 4 2 (comparing index 1 and 2)
7 9 5 4 2 (comparing index 2 and 3)
so, 4 is the smallest number after 2.

3rd step: Searching the third minimum value ( [4, 2] is fixed)
9 7 5 4 2 (comparing index 0 and 1)
9 7 5 4 2 (comparing index 1 and 2)
so, 5 is the smallest number after [4, 2].

4th step: Searching the forth minimum value ( [5, 4, 2] is fixed)
9 7 5 4 2 (comparing index 0 and 1)
so, 7 is the smallest number after [5, 4, 2] and 9 is the greatest number.

therefore, total steps= (5-1) = (n-1)
and total times = 4+3+2+1 = 1+2+3+....+(n-1)= (n*(n-1))/2

#Stable
#Not adaptive, but can be made
#Best Case=Worst Case=O(n^2)
*/

void Bubble_Sort(ll a[], ll n)
{
    ll count = 0;

    for (ll i = 0; i < n - 1; i++)
    {
        count++;
        for (ll j = 0; j < n - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);

            // for (ll k = 0; k < n; k++)
            // cout << a[k] << " ";

            // cout << endl;
        }
        // cout << endl;
    }

    cout << "Steps: " << count << endl;
}

void Bubble_Sort_Adaptive(ll a[], ll n)
{
    ll count = 0;

    for (ll i = 0; i < n - 1; i++)
    {
        ll isSorted = 1;
        count++;

        for (ll j = 0; j < n - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
                isSorted = 0;
            }

            // for (ll k = 0; k < n; k++)
            // cout << a[k] << " ";

            // cout << endl;
        }
        if (isSorted)
            break;
        // cout << endl;
    }

    cout << "Steps: " << count << endl;
}

int main()
{
    ll a[] = {9, 3, 5, 7, 8, 1, 2};

    ll n = sizeof(a) / sizeof(ll);

    // Bubble_Sort(a, n);
    Bubble_Sort_Adaptive(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}