#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    set<string> strSet;
    string input;

    // Read input strings until "*" is encountered
    while (true) {
        cin >> input;
        if (input == "*") break;
        strSet.insert(input);
    }

    // Process commands
    while (true) {
        string cmd;
        cin >> cmd;
        if (cmd == "***") break;

        if (cmd == "find") {
            string s;
            cin >> s;
            if (strSet.find(s) != strSet.end()) cout << 1 << endl;
            else cout << 0 << endl;
        } else if (cmd == "insert") {
            string s;
            cin >> s;
            if (strSet.find(s) == strSet.end()) {
                strSet.insert(s);
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}

/* 2/5
#include<bits/stdc++.h>
using namespace std;
int main(){
    string str = "";
    while (1) {
        string input;
        cin >> input;
        if (input == "*") break;
        else str = str + " " + input;
    }

    while (1){
        string cmd;
        cin >> cmd;
        int last = str.length();
        if (cmd == "***") break;      
        else if (cmd == "find") {
            string s;
            cin >> s;
            if (str.find(s) != string::npos) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (cmd == "insert") {
            string s;
            cin >> s;
            if (str.find(s) == string::npos){
                str = str + " " + s; 
                cout << 1 << endl;
            }
            else cout << 0 << endl;
        }
    }
}
*/