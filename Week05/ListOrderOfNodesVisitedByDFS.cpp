#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
int n,m;
bool *visited;
class Graph{
    int v; //số đỉnh
    list<int> *adj; //con trỏ trỏ tơi mảng chứa danh sách các đỉnh kề

    public:
        int numVertex();
        Graph(int v); // constructor 
        ~Graph(); // destructor
        void addEdge(int u, int v);
        list<int>* getAdjList(); //getter 
        void DFS(int s);
};

list<int>* Graph::getAdjList() {
    return adj;
}

Graph::Graph(int v){
    this->v = v;
    adj = new list<int>[v+1];
    int numV = numVertex();
    visited = new bool[numV+1];
    for (int i = 0; i < numV+1; i++) visited[i] = false;
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

void Graph::DFS(int s){
    visited[s] = true;
    cout << s << " ";
    list<int>::iterator i;
    for (i = adj[s].begin(); i != adj[s].end(); ++i){
        int v = *i;
        if (!visited[v]){
            DFS(v);
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
    
    g.DFS(1);
}