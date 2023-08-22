// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int Max(int a[], int n)
{
    int mx=a[0];
    for(int i=0; i<n; i++)
        if(a[i]>mx) mx=a[i];
    return mx+1;
}
void countSort(int a[], int n)
{
    int mx_1=Max(a, n), arr[mx_1]={0}, k=0;
    for(int i=0; i<n; i++) arr[a[i]]++;
    for(int i=0; i<mx_1; i++)
        for(int j=0; j<arr[i]; j++) a[k++]=i;
}
int main()
{
    int n=10, a[]={5, 2, 7, 1, 5, 2, 6, 9, 0, 0};
    countSort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}