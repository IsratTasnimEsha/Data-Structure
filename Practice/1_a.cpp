// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Node
{
public:
    char name;
    ll sal, cat;
};

int main()
{
    Node n[]={{'a', 100, 2}, {'b', 400, 3}, {'c', 500, 2}};
    for(ll i=0; i<3; i++)
    {
        if(n[i].cat!=3) n[i].sal+=5;
        cout<<n[i].name<<" "<<n[i].sal<<" "<<n[i].cat<<endl;
    }
    //return 0;
}