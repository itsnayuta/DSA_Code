#include <bits/stdc++.h>
using namespace std;
string s;
void ct(){
    stack<int> st;
    int n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/'){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (s[i] == '+') {
                st.push(a + b);
            }
            else if (s[i] == '-') {
                st.push(b - a);
            }
            else if (s[i] == '/') {
                st.push(b / a);
            }
            else if(s[i] == '*') {
                st.push(a * b);
            }
        }
        else st.push(s[i] - '0');
    }
    cout << st.top() << endl;
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> s;
        ct();
    }
}