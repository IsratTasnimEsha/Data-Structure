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

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());

    for (ll i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
            i++;
        }

        else if (infix[i] == ')')
        {
            infix[i] = '(';
            i++;
        }
    }

    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

float prefixEval(string prefix)
{
    stack<float> stk;

    for (ll i = prefix.size() - 1; i >= 0; i--)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
            stk.push(float(prefix[i] - '0'));

        else
        {
            ll a = stk.top();
            stk.pop();
            ll b = stk.top();
            stk.pop();

            float p;

            if (prefix[i] == '+')
                p = a + b;

            if (prefix[i] == '-')
                p = a - b;

            if (prefix[i] == '*')
                p = a * b;

            if (prefix[i] == '/')
                p = a / b;

            if (prefix[i] == '^')
                p = pow(a, b);

            stk.push(p);
        }
    }
    return stk.top();
}

int main()
{
    string s = "7+(9-5^2)*2";

    string prefix = infixToPrefix(s);
    cout << prefix << endl;

    float t = prefixEval(prefix);
    cout << t;
}