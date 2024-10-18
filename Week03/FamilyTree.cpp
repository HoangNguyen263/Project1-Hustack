#include<bits/stdc++.h>
using namespace std;
struct personNode {
    string name;
    int des = 0; //luu so hau due cua nguoi nay
    int gen = 0; //luu the he cua nguoi nay
    struct personNode *par = NULL;
    vector<struct personNode*> childs;
};

typedef struct personNode personNode;

set<personNode*> personList;//luu toan bo so nguoi

personNode *makeNode(string p){
    personNode *temp = new personNode();
    
    temp->name = p;
    return temp;
    
}

void addPerson(string childName, string parentName){
    //tim nguoi trong danh sach
    personNode *child = NULL;
    personNode *parent = NULL;
    for (auto it = personList.begin(); it != personList.end(); it++){
        personNode *p = *it;
        if (p->name == childName) child = p;
        else if (p->name == parentName) parent = p;
    }
    if (child == NULL) child = makeNode(childName);
    if (parent == NULL) parent = makeNode(parentName);
    personList.insert(child);
    personList.insert(parent);

    parent->childs.push_back(child);
    child->par = parent;

    //cap nhat gen
    parent->gen = child->gen + 1;
    int tempDes = parent->gen;
    personNode *parentTemp = parent->par;
    while (parentTemp != NULL){
        parentTemp->gen = tempDes + 1;
        tempDes = parentTemp->des;
        parentTemp = parentTemp->par;
    }

    //cap nhat des
    parent->des += child->des+1;
    tempDes = child->des;
    parentTemp = parent->par;
    while (parentTemp != NULL){
        parentTemp->des += tempDes + 1;
        parentTemp = parentTemp->par;
    }


}

int main(){
    while (1){
        string child;
        cin >> child;
        if (child == "***"){
            break;
        } else {
            string parent;
            cin >> parent;
            addPerson(child,parent);
        }
    }

    while(1){
        string query; cin >> query;
        if(query == "***") break;
        else if(query == "generation"){
            string personName; 
            cin >> personName;
            for(auto it = personList.begin(); it != personList.end(); it++) {
                personNode *person = *it;
                if (person->name == personName) cout << person->gen << endl;
            }
        }
        else if (query == "descendants"){
            string personName; cin >> personName;
            for(auto it = personList.begin(); it != personList.end(); it++) {
                personNode *person = *it;
                if (person->name == personName) cout << person->des << endl;
            }
        }
    }
    return 0;
    }
