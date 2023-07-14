#include <bits/stdc++.h>
using namespace std;
string s;

void ct(){
    int n =s.size();
    stack<char> st;
    for(int i = 0; i < n; i++){
        if (s[i] == '(') st.push(s[i]);
        else {
            if (!st.empty() && s[st.top()] == '(')
                st.pop();
            else st.push(i);  
        }
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        ct();
    }
}
// not complete