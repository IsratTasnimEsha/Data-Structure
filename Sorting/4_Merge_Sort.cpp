#include <bits/stdc++.h>
using namespace std;

void _merge(int a[], int p, int q, int rr)
{
    int n1 = q - p + 1;
    int n2 = rr - q;
    int l[n1], r[n2], i, j, k;

    for (i = 0; i < n1; i++)
        l[i] = a[i + p];

    for (j = 0; j < n2; j++)
        r[j] = a[j + (q + 1)];

    i = 0, j = 0;

    for (k = p; i < n1 && j < n2; k++)
    {
        if (l[i] < r[j])
            a[k] = l[i++];

        else
            a[k] = r[j++];
    }

    while (i < n1)
        a[k++] = l[i++];

    while (j < n2)
        a[k++] = r[j++];
}

void mergeSort(int a[], int p, int r)
{
    int q;

    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        _merge(a, p, q, r);
    }
}

int main()
{
    int n = 8;
    int a[] = {8, 5, 2, 3, 2, 9, 6, 7};

    mergeSort(a, 0, n - 1);
    
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}