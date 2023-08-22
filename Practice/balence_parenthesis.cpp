// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll Pair(char a, char b)
{
    if((a=='(' && b==')') || (a=='{' && b=='}') || (a=='[' && b==']')) return 1;
    else return 0;
}
void balence(string s)
{
    stack<char>st;
    ll f=1;
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
        else
        {
            if(i==0)
            {
                f=0;
                break;
            }
            if(Pair(st.top(), s[i])) st.pop();
            else st.push(s[i]);
        }
    }
    if(f==0) cout<<"NO"<<endl;
    else
    {
        if(st.empty()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int main()
{
    string s = "(([]){}){";
    balence(s);
}