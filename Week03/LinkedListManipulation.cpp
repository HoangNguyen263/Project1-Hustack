#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000];

struct Node{
	int data;
	struct Node *next;
};

typedef struct Node Node;

Node *head = NULL;

Node *makeNode(int x){
	Node *t = (Node*)malloc(sizeof(Node));
	if (t == NULL){
		printf("Heap is full");
		exit(0);
	}
	t->data = x;
	t->next = NULL;
	return t;
}

void printList(Node *h){
	Node *p = h;
	while (p != NULL){
		printf("%d ",p->data);
		p = p->next;
	}
}

//Search
Node *locate(Node *h, int x){
	Node *p = h;
	while (p != NULL){
		if (p->data == x) return p;
		p = p->next;
	}
	return NULL;
}

Node *prev(Node *h, Node *p){
	Node *t = h;
	while (t->next != p){
		t = t->next;
	}
	return t;
}

//Insert

void insertHead2(int x){
	Node *t = makeNode(x);
	t->next = head;
	head = t;
}

void insertLast(Node *p,int x){
	Node *t = makeNode(x);
	if (t == NULL) printf("full");
	while (p->next != NULL){
		p = p->next;
	}
	p->next = t;
}

void insertPrev(Node *h,Node *q, int x){
	Node *t = makeNode(x);
	Node * p = h;
	if (q == head) insertHead2(x);
	else {
		while (p->next != q){
		p = p->next;
	}
	t->next = p->next;
	p->next = t;
	}
}

void insertAfter(Node *q, int x){
	Node *t = makeNode(x);
	Node * p = head;
	if (head == NULL) {
		head = t;
	} else {
		while (p != q){
		p = p->next;
	}
	t->next = q->next;
	q->next = t;
	}
	
}

//Delete
void deleteHead(){
	Node *t = head;
	head = t->next;
	free(t);
}
void deleteAt(Node *h, Node *p){
	if (p == h) deleteHead();
	else {
		Node *t = h;
		while (t->next != p){
			t = t->next;
		}
		t->next = p->next;
		free(p);

	}
}

//Ham kiem tra k co trong dslk khong
bool check(int k){
    Node *p = head;
    while (p != NULL){
        if (p->data == k) return true;
        p = p->next;
    }
    return false;
}

//Reverse dung cua so truot r,p,q
void reverse(){
	Node *p,*q,*r;
	p = head;
	q = r = NULL;
	while (p != NULL){
		//slide
		r = q;
		q = p;
		p = p->next;
		//reverse
		q->next = r;
	}
	head = q;
	
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
	Node *p,*temp;
	for (int i = 1; i <= n; i++){
		Node *t = makeNode(a[i]);
		if (i == 1){
			head = t;
			p = head;
		} else {
			p->next = t;
			p = t;
		}
	}

    while (1){
        string command;
        cin >> command;
        if (command == "#") break;
        else if (command == "addlast"){
            int k;
            cin >> k;
            if (check(k) == 0) insertLast(head,k);
        } 
        else if (command == "addfirst"){
            int k;
            cin >> k;
            if (check(k) == 0) insertHead2(k);
            
        }
        else if (command == "addafter"){
            //printList(head); cout << "\n";
            int u,v;
            cin >> u >> v;
            //cout << check(u) << " " << check(v) << "\n";
            if (check(v) == false) continue;
            else if (check(u) == true) continue;
            else if (check(u) == false && check(v) == true){
                Node *temp = locate(head,v);
                insertAfter(temp,u);
            }
            
        }
        else if (command == "addbefore"){
            //printList(head); cout << "\n";
            int u,v;
            cin >> u >> v;
            //cout << check(u) << " " << check(v) << "\n";
            if (check(v) == false) continue;
            else if (check(u) == true) continue;
            else if (check(u) == false && check(v) == true){
                Node *temp = locate(head,v);
                insertPrev(head,temp,u);
            }
            
        }
        else if (command == "remove"){
            int k;
            cin >> k;
            if (check(k) == false) continue;
            Node *temp = locate(head,k);
            deleteAt(head,temp);

        }
        else if (command == "reverse"){
            reverse();
            
        }
    }
	
	printList(head);
	return 0;
}

