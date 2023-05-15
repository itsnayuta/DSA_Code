#include<bits/stdc++.h>
using namespace std;

void ct(string s){
    int n = s.size();
    stack<char> st;
    int cnt = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == '(')
            st.push(s[i]);
        else {
            if (!st.empty() && st.top() == '('){
                cnt += 2;
                st.pop();
            }
            else 
                st.push(s[i]);
        }
    }

    cout << cnt << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        ct(s);
    }
}