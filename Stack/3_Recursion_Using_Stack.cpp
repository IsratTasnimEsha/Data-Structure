// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    stack<ll> st;

    st.push(0);
    st.push(1);

    for (ll i = 0; i < 13; i++)
    {
        ll a = st.top();
        st.pop();

        ll b = st.top();
        st.pop();

        ll c = a + b;

        st.push(b);
        st.push(a);
        st.push(c);
    }

    for(ll i=0; i<15; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}