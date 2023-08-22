// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *next;
} * head, *head1, *head2, *temp;

void creation(int m, Node **head)
{
    Node *p = new Node();
    p->info = m;
    p->next = NULL;

    if (*head == NULL)
    {
        *head = p;
        temp = p;
    }

    else
    {
        temp->next = p;
        temp = temp->next;
    }
}

void traverse(Node **head)
{
    Node *srt = *head;

    while (srt != NULL)
    {
        // cout << srt->info <<" "<<srt->next<<endl;
        cout << srt->info << " ";
        srt = srt->next;
    }

    cout << endl
         << endl;
}

void Reverse(Node **head)
{
    Node *Current = *head, *Next = NULL, *Prev = NULL;

    while (Current != NULL)
    {
        Next = Current->next;
        Current->next = Prev;

        Prev = Current;
        Current = Next;
    }
    *head = Prev;
}

void Add()
{
    Reverse(&head1);
    Reverse(&head2);

    Node *srt1 = head1, *srt2 = head2;

    int p = srt1->info + srt2->info;
    int sum = p % 10;
    int carry = p / 10;

    srt1->info = sum;

    srt1 = srt1->next;
    srt2 = srt2->next;

    while (srt1->next != NULL)
    {
        p = srt1->info + srt2->info + carry;
        sum = p % 10;
        carry = p / 10;

        srt1->info = sum;

        srt1 = srt1->next;
        srt2 = srt2->next;
    }

    p = srt1->info + srt2->info + carry;
    sum = p % 10;
    carry = p / 10;

    srt1->info = sum;

    if(carry!=0)
    {
        Node *p=new Node();
        p->info=carry;
        p->next=NULL;
        srt1->next=p;
    }

    Reverse(&head1);
}

int main()
{
    int a[] = {9, 2, 9, 4, 5};
    int b[] = {5, 7, 6, 2, 9};

    for (int i = 0; i < 5; i++)
        creation(a[i], &head1);

    for (int i = 0; i < 5; i++)
        creation(b[i], &head2);

    Add();

    traverse(&head1);

    //Reverse(&head1);
    //traverse(&head1);
}