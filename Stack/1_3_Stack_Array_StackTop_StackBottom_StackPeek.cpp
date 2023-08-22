// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

class Stack
{
public:
    ll size;
    ll top;
    ll *array;
} * st;

ll isEmpty()
{
    if (st->top == -1)
        return 1;

    else
        return 0;
}

ll isFull()
{
    if (st->top == st->size - 1)
        return 1;

    else
        return 0;
}

void push(Stack *ptr, ll m)
{
    if (isFull())
        cout << "Stack Overflow for Element " << m << "." << endl;

    else
    {
        ptr->top++;
        ptr->array[ptr->top] = m;
    }
}

ll stackTop(Stack *ptr)
{
    return ptr->array[ptr->top];
}

ll stackBottom(Stack *ptr)
{
    return ptr->array[0];
}

ll stackPeek(Stack *ptr, ll index)
{
    return ptr->array[ptr->top - index];
}

int main()
{
    st = new Stack();

    st->size = 5;
    st->top = -1;
    st->array = new ll[st->size];

    ll a[] = {15, 26, 34, 46, 56, 67, 74};

    for (ll i = 0; i < 7; i++)
        push(st, a[i]);

    cout << "StackTop: " << stackTop(st) << endl;
    cout << "StackBottom: " << stackBottom(st) << endl;

    cout << "Peeking elements from top: ";
    for (ll i = 0; i <= st->top; i++)
        cout << stackPeek(st, i) << " ";
    cout << endl;
}