#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int T;
int n,m;

class Graph
{
    int v; //số đỉnh
    list<int> *adj; //con trỏ trỏ tơi mảng chứa danh sách các đỉnh kề

    public:
        int numVertex();
        Graph(int v); // constructor 
        ~Graph(); // destructor
        void addEdge(int u, int v);
        list<int>* getAdjList(); //getter
};
list<int>* Graph::getAdjList() {
    return adj;
}

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v];
}

int Graph::numVertex(){
    return v;
}

void Graph::addEdge(int u, int v){
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
}

Graph::~Graph() {
    delete[] adj;
}

//hàm kiểm tra đỉnh v có thể được thêm vào vị trí pos trng chu trình đang xét hay không
//path là mảng lưu các đỉnh đã được thêm vào chu trinh
bool isSafe(Graph *g,int v, int path[], int pos){
    list<int>* adjList = g->getAdjList();
    //kiểm tra xem v có phải đỉnh kề với đỉnh trước đó được thêm khôngkhông
    list<int>::iterator i;
    bool findV = false;
    for (i = adjList[path[pos-1]].begin(); i != adjList[path[pos-1]].end(); ++i){
        if (v == *i) findV = true;
    }

    if (findV == false) return false;

    //kiểm tra xem v đã được thêm vào chu trình đang xét chưa
    for (int j = 0; j < pos; j++){
        if (path[j] == v) return false;
    }

    return true;
}

//
bool hamCycleTry(Graph *g,int path[],int pos){

    //trường hợp cơ  sở: tất cả các đỉnh đã được thêm vào chu trình
    if (pos == n){
        //kiểm tra xem đỉnh cuối được thêm vào có kề vơí đỉnh đầu tiên không
        list<int>* adjList = g->getAdjList();
        list<int>::iterator i;
        bool findPos = false;
        for (i = adjList[0].begin(); i != adjList[0].end(); ++i){
            if (path[pos-1] == *i) findPos = true;
        }
        if (findPos == false) return false;
        else return true;
    } 

    //xét đỉnh khác là ứng cử   viên tiếp theo, ko xét đỉnh đầu
    for (int v = 1; v < n; v++){
        if (isSafe(g,v,path,pos)){
            path[pos] = v;
            if (hamCycleTry(g,path,pos + 1) == true)
                return true;

            path[pos] = -1;
        }
    }

    return false;
}


int main(){

    cin >> T;
    int i = 1;
    while (i <= T){
       
        
        cin >> n >> m;
        Graph* g = new Graph(n);
        list<int> *adjList = g->getAdjList();
        int j = 1; 
        while (j <= m){
            int u,v;
            cin >> u >> v;
            g->addEdge(u,v);
            j++;
        }
        int *path = new int[n];
        for (int i = 0; i < n; i++) path[i] = -1;

        path[0] = 0;
        if (hamCycleTry(g,path,1) == false){
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }

        delete[] path;
        delete g;
        i++;
    }

    
    
}