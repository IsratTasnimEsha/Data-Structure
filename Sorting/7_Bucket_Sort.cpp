// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>&a, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min_ind=i;
        for(int j=i+1; j<n; j++)
            if(a[j]<a[min_ind]) min_ind=j;
        swap(a[min_ind], a[i]);
    }
}
void bucketSort(int a[], int n)
{
    int mx=a[0], k=0;
    for(int i=0; i<n; i++)
        if(a[i]>mx) mx=a[i];
    int devider=mx/n;
    vector<int>vec[devider];
    for(int i=0; i<n; i++)
    {
        int j=a[i]/n;
        vec[j].push_back(a[i]);
    }
    for(int i=0; i<=devider; i++)
    {
        selectionSort(vec[i], vec[i].size());
        for(int j=0; j<vec[i].size(); j++) a[k++]=vec[i][j];
    }
}
int main()
{
    int n=10, a[]={2, 98, 71, 8, 41, 11, 33, 18, 90, 14};
    bucketSort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}