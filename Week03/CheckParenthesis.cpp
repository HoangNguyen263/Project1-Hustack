#include<bits/stdc++.h>
using namespace std;
stack<char> myStack;
string str;

int main(){
    getline(cin,str);
    
    int pos = 0;
    while (str[pos] != '\0'){
        if (str[pos] == '(' || str[pos] == '[' || str[pos] == '{'){
            myStack.push(str[pos]);
        }
        else if(str[pos] == ')' || str[pos] == ']' || str[pos] == '}'){
            if (myStack.empty()) {
                cout << "0"; 
                return 0;
            }
            if ((str[pos] == ')' && myStack.top() == '(') || 
            (str[pos] == ']' && myStack.top() == '[') ||
            (str[pos] == '}' && myStack.top() == '{')) 
                myStack.pop();
            else {
                cout << '0';
                return 0;
            }
        } 
        pos++;
        
    }

    if (myStack.empty() == true) cout << "1";
    else cout << "0";
    return 0;
}