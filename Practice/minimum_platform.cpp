//bismillahir rahmanir rahim

#include<bits/stdc++.h>
using namespace std;

#define ll long long

void Sort(ll a[], ll d[], ll n)
{
    for(ll i=0; i<n-1; i++)
    {
        for(ll j=0; j<n-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                swap(d[j], d[j+1]);
            }
        }
    }
}
int main()
{
    string ar[10]={"06:00", "00:00", "01:00", "15:00", "02:00", "02:50", "04:00", "07:00", "08:00"};
    string dp[10]={"12:00", "00:02", "01:02", "16:00", "03:00", "04:00", "05:00", "13:00", "14:00"};
    ll a[1000], d[1000], l1=0, l2=0;
    ll n=sizeof(ar)/sizeof(string);
    for(ll i=0; i<n; i++)
    {
        if(ar[i].size()==4) a[l1++]=(ar[i][0]-'0')*100+(ar[i][2]-'0')*10+(ar[i][3]-'0');
        else a[l1++]=(ar[i][0]-'0')*1000+(ar[i][1]-'0')*100+(ar[i][3]-'0')*10+(ar[i][4]-'0');

        if(dp[i].size()==4) d[l2++]=(dp[i][0]-'0')*100+(dp[i][2]-'0')*10+(dp[i][3]-'0');
        else d[l2++]=(dp[i][0]-'0')*1000+(dp[i][1]-'0')*100+(dp[i][3]-'0')*10+(dp[i][4]-'0');
    }
    Sort(a, d, n);
    ll mx=0;
    for(ll i=0; i<l1-1; i++)
    {
        ll cnt=1, p=d[i];
        while((a[i+1])<p)
        {
            //cout<<p<<" "<<a[i]<<endl;
            cnt++;
            i++;
            if(i>=(l1-2)) break;
        }
        mx=max(cnt, mx);
        //cout<<cnt<<endl;
    }
    cout<<"max: "<<mx;
}