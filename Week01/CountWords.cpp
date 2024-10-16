#include <bits/stdc++.h>
using namespace std;

int main() {
    string t;
    int word_count = 0;

    
    while (getline(cin, t)) {
        for (int i = 0; i < t.length(); i++) {
            
            if (!isspace(t[i])) {
                word_count++;

                
                while (i < t.length() && !isspace(t[i])) {
                    i++;
                }
            }
        }
    }

    
    cout << word_count << endl;

    return 0;
}
