/// bismillahir rahmanir rahim

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

void merge()
{
    Node *srt;

    if(head1->info<head2->info)
    {
        head=srt=head1;
        head1=head1->next;
    }

    else
    {
        head=srt=head2;
        head2=head2->next;
    }

    while(head1 && head2)
    {
        if(head1->info>head2->info)
        {
            srt->next=head2;

            head2=head2->next;
            srt=srt->next;   
        }

        else
        {
            srt->next=head1;

            head1=head1->next;
            srt=srt->next;
        }
    }

    if (head1 != NULL)
        srt->next = head1;
    
    if (head2 != NULL)
        srt->next = head2;
}

void traverse(Node **head)
{
    Node *srt = *head;

    while (srt != NULL)
    {
        //cout << srt->info <<" "<<srt->next<<endl;
        cout << srt->info <<" ";
        srt = srt->next;
    }

    cout << endl
         << endl;
}

int main()
{
    int a[] = {11, 33, 66, 99, 222};
    int b[] = {22, 33, 55, 88, 111};

    for (int i = 0; i < 5; i++)
        creation(a[i], &head1);

    for (int i = 0; i < 5; i++)
        creation(b[i], &head2);

    cout << "Initial list: ";
    traverse(&head1);

    cout << "Initial list: ";
    traverse(&head2);

    merge();
    traverse(&head);
}