#include <bits/stdc++.h>
using namespace std;
string s;

void ct(){
    stack<char> st;
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] != ')') st.push(s[i]);
        else {
            int ok = 0;
            while(!st.empty()){
                char c = st.top();
                st.pop();
                if (c == '+' || c == '-' || c == '*' || c == '/'){
                    ok = 1;
                }
                if (c == '('){
                    break;
                }
            } 
            if (ok == 0) {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
    return;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        ct();
    }
}