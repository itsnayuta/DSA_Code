#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
    int t; cin >> t;
    while(t--){
        stack<string> st;
        cin.ignore();
        getline(cin, s);
        stringstream ss(s);
        string tmp;
        while(ss >> tmp){
            st.push(tmp);
        }
        while(!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
}