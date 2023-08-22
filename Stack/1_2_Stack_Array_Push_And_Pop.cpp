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

ll pop(Stack *ptr)
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return -1;
    }

    else
    {
        ll m = ptr->array[ptr->top];
        ptr->top--;
        return m;
    }
}

int main()
{
    st = new Stack();

    st->size = 4;
    st->top = -1;
    st->array = new ll[st->size];

    push(st, 15);
    push(st, 26);
    push(st, 34);
    push(st, 56);
    push(st, 67);
    push(st, 79);

    cout << "After pushing elements: ";
    for (ll i = 0; i <= st->top; i++)
        cout << st->array[i] << " ";
    cout << endl;

    cout << "After popping last element " << pop(st) << ": ";
    for (ll i = 0; i <= st->top; i++)
        cout << st->array[i] << " ";
    cout << endl;

    cout << "Deleting remainig elements: " << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << pop(st) << endl;
    cout << endl;
}