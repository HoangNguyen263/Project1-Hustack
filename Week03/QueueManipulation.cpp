#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void push(int x){
    struct Node *t;
    t=(struct Node*)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue is FUll\n");
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int pop(){
    int x;
    struct Node* t;
    if(front==NULL) x = -1;
    else{
        x=front->data;
        t=front;
        front=front->next;
        free(t);
    }
    return x;
}


int main(){
    while (1){
        string command;
        cin >> command;
        if (command == "PUSH"){
            int v;
            cin >> v;
            push(v);
        } 
        else if(command == "POP"){
            int v= pop();
            if (v == -1) cout << "NULL" << "\n";
            else cout << v << "\n";
        }
        else if (command == "#") break;
    }
    return 0;
}