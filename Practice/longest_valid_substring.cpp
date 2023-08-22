// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void balence(string s)
{
    stack<char> st;
    st.push(-1);
    
    ll result = 0;

    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(i);

        else
        {
            if (!st.empty())
                st.pop();
            
            if (!st.empty())
                result = max(result, i - st.top());
            
            else
                st.push(i);
        }
    }
    cout << result;
}

int main()
{
    string s = ")(()()()(()";
    balence(s);
}

//()()((())()