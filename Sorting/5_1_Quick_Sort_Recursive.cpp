// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define dl double
#define st string
#define ch char

/*
Given array: 2 4 3 9 1 4 8 7 5 6

Step 1: 1st element as reference. Smaller than reference-> left side, greater than reference-> right side.

Partitioning procedure:
Reference= 2 (pivot)
low=i= reference index+1=0+1=1, and, high=j=n-1=10-1=9.
i++ and we find greater than 2, and,  j-- untill we find smaller than 2.
a[i]=a[1]=4 is greater than 2, and, a[j]=a[4]=1 is smaller than 2.
Interchange the elements of index 1 and 4.
So, New array= 2 1 3 9 4 4 8 7 5 6

Again repeat same procedure untill i<j.
Then,  a[i]=a[2]=3 is greater than 2, and, a[j]=a[1]=1 is smaller than 2.
Here, i=2, j=1, means, i>j.
Stop the process and interchange elements of reference index with element of j.
So, New array= 1 2 3 9 4 4 8 7 5 6

Index of 2 is fixed now and it's index is j(partition index) now.
2 is sorted because smaller than 2's are at left side and greater than 2's are at right side of 2.

Step 2: patitioning

There are 2 subarrays for every fixed position after step 1.
part-1: left side of 2 (left subarray)
part-2: right side of 2 (right subarray)

for every subarray, follow step-1.
It's a recursive program.

EXAMPLE: 2 1 5 9 4.....(1)

Step-1:
{
    pivot=2, after swaping 1 and 2, 2 is fixed, new array 1 2 5 9 4.....(2)

    Step-2.1: left subarray=[1]
    {
        [1] is sorted.
        New array=[1, 2, 5, 4, 9]....[3]
    }

    Step-2.2: right subarray=[5, 9, 4]
    {
        pivot=5, 9 is greater than pivot, 4 is smaller than pivot.
        So, i=3, j=4 and i<j.  (as per main swaped array(3), not subarray)
        So, swap a[i] with a[j]
        New subarray [5, 4, 9]
        Therefore, New array [1, 2, 5, 4, 9].....(4)

        pivot=5, 9 is greater than pivot, 4 is smaller than pivot.
        So, i=4, j=3 and i>j. (as per main swaped array(4), not subarray)
        So, swap a[j] with a[reference index]
        New subarray [4, 5, 9]
        Therefore, New array [1, 2, 4, 5, 9].....(5)

        Step-3.1: left subarray=[2, 4]
        {
            pivot=2, 4 is greater than pivot.
            So, i=2 (as per main swaped array(5), not subarray)
            Therefore, New array [1, 2, 4, 5, 9].....(4)
        }

        Step-3.2: right subarray=[9]
        {
            [9] is sorted.
            New array=[1, 2, 4, 5, 9]'''''''9. 
        }
    }
}

#Worst case: O(n^2) [Already sorted array]
Total steps= (5-1) = (n-1)
and total times = 1+2+3+4 = 1+2+3+....+(n-1)= (n*(n-1))/2

#Best Case: 0(n*log(n))
*/

ll Partition(ll a[], ll low, ll high)
{
    ll pivot = a[low];

    ll i = low + 1;
    ll j = high;

    do
    {
        while (a[i] <= pivot)
            i++;

        while (a[j] > pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);

    } while (i < j);

    swap(a[low], a[j]);

    return j;
}

void Quick_Sort(ll a[], ll low, ll high)
{
    if(low<high){
        ll partition_index= Partition(a, low, high);

        Quick_Sort(a, low, partition_index-1);
        Quick_Sort(a, partition_index+1, high);
    }
}

int main()
{
    ll a[] = {5, 0, 8, 6, 9, 2, 4, 7};

    ll n = sizeof(a) / sizeof(ll);

    Quick_Sort(a, 0, n - 1);

    for (ll i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}