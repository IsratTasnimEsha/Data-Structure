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
};

ll isEmpty(Stack *st)
{
    if (st->top == -1)
        return 1;

    else
        return 0;
}

ll isFull(Stack *st)
{
    if (st->top == st->size - 1)
        return 1;

    else
        return 0;
}

int main()
{
    Stack *st = new Stack();

    st->size = 3;
    st->top = -1;
    st->array = new ll[st->size];

    st->array[0] = 4;
    st->array[1] = 5;
    st->array[2] = 6;
    st->top += 3;

    if (isEmpty(st))
        cout << "Stack is Empty." << endl;

    else
        cout << "Stack is not Empty." << endl;

    if (isFull(st))
        cout << "Stack is Full." << endl;

    else
        cout << "Stack is not Full." << endl;
}