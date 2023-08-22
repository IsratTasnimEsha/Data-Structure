// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return 0;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string postfix;
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            postfix += s[i];

        else if (s[i] == '(') st.push('(');

        else if(s[i]==')')
        {
            while (st.top() != '(')
            {
                postfix+=st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                postfix+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    return postfix;
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
            i++;
        }
        if(s[i]==')')
        {
            s[i]='(';
            i++;
        }
    }
    s=infixToPostfix(s);
    reverse(s.begin(), s.end());
    return s;
}

ll Evaluation(string s, ll n)
{
    stack<ll>st;
    if(n==1) reverse(s.begin(), s.end());
    for(ll i=0; i<s.size(); i++)
    {
        if(s[i]>='0' && s[i]<='9') st.push(s[i]-'0');
        else
        {
            ll a, b;
            if(n==0)
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
            }
            else
            {
                b=st.top();
                st.pop();
                a=st.top();
                st.pop();
            }
            if(s[i]=='+') st.push(b+a);
            if(s[i]=='-') st.push(b-a);
            if(s[i]=='*') st.push(b*a);
            if(s[i]=='/') st.push(b/a);
            if(s[i]=='^') st.push(pow(b,a));
        }
    }
    return st.top();
}

int main()
{
    string s = "7+(9-5^2)*2";
    s="("+s+")";
    string post = infixToPostfix(s);
    cout << "Postfix: "<<post<<endl;
    cout<<"postEv: "<< Evaluation(post, 0)<<endl;
    string pre = infixToPrefix(s);
    cout << "Prefix: "<<pre<<endl;
    cout<<"preEv: "<< Evaluation(pre, 1)<<endl;
}