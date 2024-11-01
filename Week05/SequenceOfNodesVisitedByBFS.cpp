#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n,m;
int *id;
int cnt; //số thành phần liên thông 
class Graph{
    int v; //số đỉnh
    list<int> *adj; //con trỏ trỏ tơi mảng chứa danh sách các đỉnh kề

    public:
        int numVertex();
        Graph(int v); // constructor 
        ~Graph(); // destructor
        void addEdge(int u, int v);
        list<int>* getAdjList(); //getter 
        void BFS(int s);
        void sortAdj();
};

list<int>* Graph::getAdjList() {
    return adj;
}

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v+1];
    int numV = numVertex();
    id = new int[numV+1];
     for (int i = 0; i < numV+1; i++) id[i] = 0;
}

int Graph::numVertex(){
    return v;
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::BFS(int s){
    queue<int> q;
    q.push(s);
    id[s] = cnt;
    
    list<int>::iterator i;
    while(!q.empty()){
        s = q.front();
        cout << s << " ";
        q.pop();

        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            int v = *i;
            if (id[v] == 0){
                id[v] = cnt;
                q.push(v);
            }
        }
    }

}

int main(){
    cin >> n >> m;
    Graph g(n);
    int p = 1;
    while (p <= m){
        int u,v;
        cin >> u >> v;
        g.addEdge(u,v);
        p++;
    }

    list<int> *adj = g.getAdjList();
    for (int i = 1; i <= n; i++){
        adj[i].sort();
    }
    cnt = 0;
    //dựa trên số thành phần liên thông để duyệt BFS toàn đô thị
    for (int i = 1; i <= n; i++){
        if (id[i] == 0){
            cnt += 1;
            g.BFS(i);
        }
    }
    
}