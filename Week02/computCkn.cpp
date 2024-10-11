#include<bits/stdc++.h>
using namespace std;
int res[1000][1000];
const int MOD = 1e9 + 7;
int cKn(int k, int n){
    int p;
    if (k == 0 || k == n) {
        res[k][n]=1;

    }
    else {
        if (res[k][n] < 0)
            res[k][n] = (cKn(k-1,n-1)+cKn(k,n-1))%MOD;
    }
    return res[k][n];
    
}
int main(){
    int k,n;
    
    cin >> k >> n;
    for (int i =0; i <=n; i++)
    for (int j = 0; j <= n; j++)
    res[i][j] = -1;
    cout << cKn(k,n);

}