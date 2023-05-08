#include <bits/stdc++.h>
using namespace std;
string s;
stack<int> st;

int main(){
	while(cin >> s) {
		if (s == "push"){
			int n; cin >> n;
			st.push(n);
		}
		if (s == "pop"){
			st.pop();
		}
		if (s == "show"){
			if (st.empty()) {
				cout << "empty" << endl;
			}
			else {
				stack<int> q = st;
				vector<int> v;
				while(!q.empty()){
					int n = q.top();
					v.push_back(n);
					q.pop();
				}
				for (int i = v.size() - 1; i >= 0; i--){
					cout << v[i] << " ";
				}
				cout << endl;
			}
		}
	}
}
