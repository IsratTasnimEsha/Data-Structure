// bismillahir rahmanir rahim

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class Node
{
public:
    ll data;
    Node *left, *right;
};

Node* newNode()
{
    ll ch, d;
    Node *temp=new Node;
    cout<<"-1 to exit."<<endl<<"0 for new node."<<endl<<"Choice? ";

    cin>>ch;
    if(ch==-1) return 0;

    else
    {
        cout<<"Data? ";
        cin>>d;
        temp->data=d;

        cout<<"Left child of "<<d<<"? ";
        cout<<endl;
        temp->left=newNode();

        cout<<"Right child of "<<d<<"? ";
        cout<<endl;
        temp->right=newNode();

        return temp;
    }
}

void printInOrder(Node *node)
{
    if(node==NULL) return;

    printInOrder(node->left);
    cout<<node->data<<" ";
    printInOrder(node->right);
}

int main()
{
    Node *root=newNode();

    cout<<"InOrder Traverse: ";
    printInOrder(root);
    cout<<endl;
}