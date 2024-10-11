#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int n;
int x[MAX];
int mark[MAX] ={0};
int check(int v){
    if (mark[v] == 1) return 0;
    return 1;
}

void printSolution(){
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    cout << "\n";
}

void TRY(int k){
    for (int v = 1; v <= n; v++){
        if (check(v)){
            x[k] = v;
            mark[v] = 1;
            if (k == n) printSolution();
            else TRY(k+1);
            mark[v] = 0;
        }
        
    }
}

int main(){
    
    cin >> n;
    TRY(1);
}