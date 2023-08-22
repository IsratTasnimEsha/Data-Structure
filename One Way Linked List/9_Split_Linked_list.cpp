// Bismillahir Rahmanir Rahim

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int info;
    Node *link;
} * head, *temp, *head1, *head2;

void Creation(int n)
{
    Node *p = new Node();
    p->info = n;
    p->link = NULL;

    if (head == NULL)
    {
        head = p;
        temp = p;
    }

    else
    {
        temp->link = p;
        temp = temp->link;
    }
}

int linear_search()
{
    Node *temp = head;
    int count = 0;

    while (temp!=NULL)
    {
        count++;
        temp = temp->link;
    }

    if(count%2==0) return count/2;
    else return count/2+1;
}

void split()
{
    head1=head;
    int count=linear_search();

    for(int i=1; i<count; i++)
    {
        head=head->link;
    }
    
    head2=head->link;

    head->link=NULL;
}

void Traverse(Node **head)
{
    Node *srt = *head;

    while (srt != NULL)
    {
        cout << srt->info << " ";
        srt = srt->link;
    }

    cout << endl;
}

int main()
{
    int a[] = {0, 1, 2, 3, 4};

    for (int i = 0; i < 5; i++)
    {
        // int n;
        // cin >> n;
        Creation(a[i]);
    }

    Traverse(&head);
    split();
    Traverse(&head1);
    Traverse(&head2);
}