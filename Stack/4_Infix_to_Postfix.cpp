// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string postfix;

    for (ll i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            postfix += c;

        else if (c == '(')
            st.push('(');

        else if (c == ')')
        {
            while (st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                if (c == '^' && st.top() == '^')
                    break;
                else
                {
                    postfix += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

float postfixEval(string postfix)
{
    stack<float> stk;

    for (ll i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
            stk.push(float(postfix[i] - '0'));

        else
        {
            ll a = stk.top();
            stk.pop();
            ll b = stk.top();
            stk.pop();

            float p;

            if (postfix[i] == '+')
                p= b + a;

            if (postfix[i] == '-')
                p= b - a;

            if (postfix[i] == '*')
                p= b * a;

            if (postfix[i] == '/')
                p= b / a;

            if (postfix[i] == '^')
                p= pow(b, a);

            stk.push(p);
        }
    }
    return stk.top();
}

int main()
{
    string s = "7+(9-5^2)*2";

    string postfix = infixToPostfix(s);
    cout << postfix << endl;

    float t = postfixEval(postfix);
    cout << t;
}