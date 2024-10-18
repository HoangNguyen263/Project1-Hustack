#include<bits/stdc++.h>
using namespace std;

typedef struct TreeNode{
    int data;
    struct TreeNode *lmostchild; //trỏ đến nút con trái nhất
    struct TreeNode *rsibling;
} TreeNode;

TreeNode *root = NULL;

TreeNode *makenewnode(int x){
    TreeNode *p = new TreeNode;
    if (p == NULL){
        exit(0);
    }
    p->data = x;
    p->lmostchild = NULL;
    p->rsibling = NULL;
    return p;
}

TreeNode *find(TreeNode *r, int id){
    if (r == NULL) return NULL;
    if (r->data == id) return r;
    //không tìm thấy ở gốc thì ta sẽ tìm ở nút còn lại, bắt đầu từ nút con trái nhất
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        TreeNode *q = find(p,id);
        if (q != NULL) return q; //q khác null tức là đã tìm thấy q
        p = p->rsibling;
    }
    return NULL; //trả lại NULL nếu ko tìm thấy
}


//preOrder: visit(node),preOrder(left subtree),preOrder(right subtree)
void preOrder(TreeNode *r){
    if (r == NULL) return;
    cout << r->data << " ";
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        preOrder(p);
        p = p->rsibling;
    }
}

//postOrder: post(left subtree),post(right subtree),visit(root)
void postOrder(TreeNode *r){
    if (r == NULL) return;
    TreeNode *p = r->lmostchild;
    while (p != NULL){
        postOrder(p);
        p = p->rsibling;
    }
    cout << r->data << " ";
}

//inOrder:in(left subtree), visit(root), in(right subtree)
void inOrder(TreeNode *r){
    if (r == NULL) return;
    TreeNode *p = r->lmostchild;
    inOrder(p);
    cout << r->data <<" ";

    if (p != NULL) p = p->rsibling;
    while (p != NULL){
        inOrder(p);
        p = p->rsibling;
    }
}

int main(){
    root=NULL;
    while (1){
        string command;
        cin >> command;
        if (command == "MakeRoot"){
            int v;
            cin >> v;
            if (root == NULL) root = makenewnode(v);
        } 
        else if(command == "Insert"){
            int u,v;
            cin >> u >> v;
            TreeNode *findv = find(root,v);
            TreeNode *findu = find(root,u);
            if (findv == NULL) continue;
            else if (findu != NULL) continue;
            else if (findu == NULL && findv != NULL){
            TreeNode *nodeu = makenewnode(u);
            
            if (findv->lmostchild == NULL) findv->lmostchild = nodeu;
            else {
                TreeNode *p = findv->lmostchild;
                while (p->rsibling != NULL){
                    p = p->rsibling;
                }
                p->rsibling = nodeu;}
            }
        }
        else if(command == "InOrder"){
            inOrder(root);
        }
        else if(command == "PreOrder"){
            preOrder(root);
        }
        else if(command == "PostOrder"){
            postOrder(root);
        }
        else if (command == "*") break;
    }
    return 0;
	
}