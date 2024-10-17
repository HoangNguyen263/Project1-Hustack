#include<bits/stdc++.h>
using namespace std;

struct Stack{
	int data;
	struct Stack *next;
};
typedef struct Stack Stack;
Stack *top = NULL;

Stack *makenewnode(int x){
	Stack *t = new Stack;
	if (t == NULL) {
	exit(0);
}
	t->data = x;
	t->next = NULL;
	return t;
}

void push(int x){
	Stack *t = makenewnode(x);
	if (t == NULL) printf("Stack is full");
	else{
		t->next = top;
		top = t;
	}
}

int pop(){
	Stack *t = (Stack*)malloc(sizeof(Stack));
    int x;
	if (top == NULL){
        x = -1;
	} else{
		t = top;
		top = top->next;
        x = t->data;
		free(t);
	}
    return x;
}

void display(Stack *s){
	Stack *t = s;
	while (t != NULL){
		cout << t->data;
		t = t->next;
	}
	
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
}