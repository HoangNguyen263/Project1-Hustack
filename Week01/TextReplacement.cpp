#include<bits/stdc++.h>
using namespace std;

int main(){
    string P1, P2, T;

    getline(cin, P1);
    getline(cin, P2);
    getline(cin, T);

    
    size_t ans = 0;

    while((ans = T.find(P1, ans)) != string::npos) {
        T.replace(ans, P1.length(), P2);
        ans += P2.length();  
    }

    
    cout << T << endl;

    return 0;
}
