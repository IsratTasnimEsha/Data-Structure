// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

ll a[10];
ll i = -1;

void push(ll m)
{
    if (i == 9)
        cout << "OVERFLOW ";

    else
    {
        i++;
        a[i] = m;
    }
}

ll pop()
{
    if (i == -1)
    {
        cout << "UNDERFLOW ";
        return -1;
    }

    ll p = a[i];
    i--;
    return p;
}

int main()
{
    ll b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    for (ll j = 0; j < 12; j++)
    {
        if(i!=9)
        {   push(b[j]);
            cout << a[j] << " ";
        }
        else cout<<"OVERFLOW ";
    }

    cout << endl
         << endl;

    for (ll j = 0; j < 12; j++){
        if (i!=-1)
            cout << pop() << " ";
        else
            cout<<"UNDERFLOW ";
    }
}