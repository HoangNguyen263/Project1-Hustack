#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *makeTreeNode(int x){
    node *newNode = NULL;
    newNode = new node();
    //neu khong the cap phat bo nho
    if (newNode == NULL){
        exit(1);
    }
    else {
        newNode->data = x;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

node *insertNode(node *root, int data){
    node *newNode;
    newNode = makeTreeNode(data);
    if (root == NULL) return newNode;
    
    if (data < root->data){
        root->left = insertNode(root->left,data);
    } else if (data > root->data){
        root->right = insertNode(root->right,data);
    }
    return root;
}

void printPreorder(node *root){
    if (root != NULL){
        cout << root->data << " ";
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main(){
    node *BST = NULL;
    while (1){
        string s;
        getline(cin,s);
        if (s == "#") break;
        string subs = "insert ";
        int x = stoi(s.substr(subs.length()));
        BST = insertNode(BST,x);
    }
    printPreorder(BST);
}