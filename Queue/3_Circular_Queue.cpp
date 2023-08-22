// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int sz = 7;
int que[7], front = -1, rear = -1;
void Enque(int n)
{
    if (front == -1 && rear == -1)
    {
        front++;
        rear++;
        que[rear] = n;
    }
    else
    {
        rear = (rear + 1) % sz;
        que[rear] = n;
    }
}
void Deque()
{
    if (front == rear)
        front = rear = -1;

    else
        front = (front + 1) % sz;
}
int main()
{
    Enque(3);
    Enque(4);
    Enque(5);
    Enque(6);
    Deque();
    Deque();
    Deque();
    Enque(7);
    Enque(8);
    Enque(9);
    Enque(10);
    Enque(11);
    Enque(12);
    // Enque(13);

    cout << front << " " << rear << endl;

    if (front == rear)
        cout << "Queue is Full." << endl;

    else
    {
        for (int i = front; i != rear; i = (i + 1) % sz)
            cout << que[i] << " ";
        cout << que[rear];
    }
}