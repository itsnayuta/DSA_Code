#include <bits/stdc++.h>
using namespace std;
string s;
stack<int> st;

int main(){
	while(cin >> s) {
		if (s == "PUSH"){
			int n; cin >> n;
			st.push(n);
		}
		if (s == "POP"){
			if (!st.empty()){
				st.pop();
			}
		}
		if (s == "PRINT"){
			if (st.empty()) {
				cout << "NONE" << endl;
			}
			else {
				int n = st.top();
				cout << n << endl;
			}
		}
	}
}
