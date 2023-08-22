// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int main()
{
    float up=5.2, lb=4, h=.2;
    float n=((up-lb)/h);
    float y[7];
    for(int i=0; i<=6; i++)
        y[i]=log(lb+h*i);
    float s1=0.0, s2=0.0, s3=0.0;
    s1=y[0]+y[6];
    for(int i=1; i<6; i++)
    {
        if(i%2==1) s2+=y[i];
        else s3+=y[i];
    }
    cout<<(h/3)*(s1+4*s2+2*s3);
}