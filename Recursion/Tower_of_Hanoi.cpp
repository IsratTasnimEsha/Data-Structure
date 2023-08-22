// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void towerOfHanoi(ll n, char from, char to, char aux)
{
    if(n==0) return;
    towerOfHanoi(n-1, from, aux, to);
    cout<<"Disk "<<n<<" moved from "<<from<<" to "<<to<<"."<<endl;
    towerOfHanoi(n-1, aux, to, from);
}

int main()
{
    towerOfHanoi(4, 'A', 'C', 'B');
}