// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

/*
Given array: 7 2 91 77 3

Step 1:
sorted: [7], unsorted [2, 91, 77, 3]
2 is taken.
[2, 7, 91, 77, 3]   #2<7

Step 2:
sorted [2, 7], unsorted [91, 77, 3]
91 is taken.
[2, 7, 91, 77, 3]   #91>7 and 91>2

Step 3:
sorted [2, 7, 91], unsorted [77, 3]
77 is taken.
[2, 7, 77, 91, 3]   #77<91 and 77>7 and 77>2

Step 4:
sorted [2, 7, 77, 91], unsorted [3]
3 is taken.
[2, 3, 7, 77, 91]   #3<91 and 3<77 and 3<7 and 3>2

Total steps= (5-1) = (n-1)
and total times = 1+2+3+4 = 1+2+3+....+(n-1)= (n*(n-1))/2

#Stable
#Adaptive
#Best Case=O(n)
#Worst Case=O(n^2)
Total steps= (5-1) = (n-1)
and total times = 1+2+3+4 = 1+2+3+....+(n-1)= (n*(n-1))/2
*/

void insertionSort(int a[], int n)
{
    for(int i=1; i<n; i++)
    {
        int m=a[i], j=i-1;
        while (j>=0 && a[j]>m)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=m;
    }
}

int main()
{
    ll a[] = {12, 54, 65, 7, 23, 9};
    ll n = sizeof(a) / sizeof(ll);

    Insertion_Sort(a, n);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}