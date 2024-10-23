#include<bits/stdc++.h> 
using namespace std;
int n;
int a[100000];
set<int> c; //set de kiem tra phan tu da xuat hien chua
int res[100000];
int main(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (c.find(a[i]) != c.end()) res[i] = 1;
        c.insert(a[i]);
    }

    for (int i = 0; i < n; i++){
        cout << res[i] << endl;
    }

}