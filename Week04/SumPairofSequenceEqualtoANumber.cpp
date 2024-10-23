#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,M;

int main(){
    cin >> n >> M;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    std::sort(a, a+n);
    int Q = 0;
    int i = 0, j = n-1;
    while (i < j){
        if (a[i] + a[j] > M) j--;
        else if (a[i] + a[j] < M) i++;
        else if (a[i] + a[j] == M) {
            Q += 1;
            i++;
            j--;
        }
    }
    cout << Q;
    return 0;
}