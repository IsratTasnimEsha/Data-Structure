// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

void insertionSort(string a[], int n)
{
    for(int i=1; i<n; i++)
    {
        string m=a[i];
        int k=-1;        
        for(int j=i-1; j>=0; j--)
            if(m<a[j])
            {
                a[j+1]=a[j];
                k=j;
            }
        if(k!=-1) a[k]=m;
    }
}
void radixSort(string a[], int n)
{
    int ind=a[0].size();
    while(ind--)
    {
        int k=0;
        vector<string>vec[10];
        for(int i=0; i<n; i++)
            for(int j=0; j<10; j++)
                if(a[i][ind]==j+48) vec[j].push_back(a[i]);
        for(int i=0; i<10; i++)
        {
            string s[100];
            int l=0;
            for(int j=0; j<vec[i].size(); j++) s[l++]=vec[i][j];
            insertionSort(s, l);
            for(int j=0; j<vec[i].size(); j++) a[k++]=s[j];
        }
    }
}
int main()
{
    int n=10;
    string a[]={"512", "015", "507", "963", "507", "140" , "216", "000", "431", "025"};
    radixSort(a, n);
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}