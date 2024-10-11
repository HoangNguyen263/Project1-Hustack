#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int n;
int a[MAX];
void print(){
    for (int i = 1; i <= n; i++){
        cout << a[i];
    }
    cout << "\n";
}

int check(int v,int k){
    return 1;
}

void TRY(int k){
    for (int v = 0; v <= 1; v++){
        if(check(v,k)){
            a[k] = v;
            if (k==n) print();
            else TRY(k+1);
        }
    }
}

int main(){
    cin >> n;
    TRY(1);
}