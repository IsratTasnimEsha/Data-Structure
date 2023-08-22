// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int que[1000], front = -1, rear = -1;

void push_Front(int n)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        que[rear] = n;
    }
    else
    {
        front--;
        que[front] = n;
    }
}

void push_Back(int n)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        que[rear] = n;
    }
    else
    {
        rear++;
        que[rear] = n;
    }
}

void pop_Front()
{
    front++;
}

void pop_Back()
{
    rear--;
}

int main()
{
    push_Back(6);
    push_Back(7);
    push_Back(8);
    pop_Front();
    pop_Front();
    push_Front(1);
    push_Back(9);
    pop_Back();

    cout << front << " " << rear << endl;

    if (front >= rear)
        cout << "Queue is Empty." << endl;

    else
        for (int i = front; i <= rear; i++)
            cout << que[i] << " ";
}