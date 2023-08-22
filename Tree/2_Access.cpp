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

Node* newNode(ll d)
{
    Node *temp=new Node;
    temp->data=d;
    temp->left=temp->right=NULL;
    return temp;
}

void printInOrder(Node *node)
{
    if(node==NULL) return;

    printInOrder(node->left);
    cout<<node->data<<" ";
    printInOrder(node->right);
}

void printPreOrder(Node *node)
{
    if(node==NULL) return;

    cout<<node->data<<" ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void printPostOrder(Node *node)
{
    if(node==NULL) return;

    printPostOrder(node->left);
    printPostOrder(node->right);
    cout<<node->data<<" ";
}

int main()
{
    Node *root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);

    cout<<"InOrder Traverse: ";
    printInOrder(root);
    cout<<endl;

    cout<<"PreOrder Traverse: ";
    printPreOrder(root);
    cout<<endl;

    cout<<"PostOrder Traverse: ";
    printPostOrder(root);
    cout<<endl;
}