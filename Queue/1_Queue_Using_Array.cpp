// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

int que[1000], front=-1, rear=-1;
void Enque(int n)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        que[rear]=n;
    }
    else
    {
        rear++;
        que[rear]=n;
    }
}
void Deque()
{
    front++;
}
int main()
{
    Enque(6);
    Enque(7);
    Enque(8);
    Deque();
    Enque(6);
    Enque(7);
    Deque();
    Deque();
    Enque(8);
    
    if(front>=rear) cout<<"Queue is Empty."<<endl;
    else
        for(int i=front; i<=rear; i++) cout<<que[i]<<" ";
}