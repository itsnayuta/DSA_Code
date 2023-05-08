#include <bits/stdc++.h>
using namespace std;
int n, check;
string s;
stack<char> st;

void ct(){
	for (int i = 0; i < n; i++){
		if (s[i] != ')') st.push(s[i]);
		else {
			check = 0;
			while(!st.empty()){
				char c = st.top();
				st.pop();
				if(c == '+' || c == '-' || c == '*' || c == '/')
					check = 1;
				if(c == '(')	break;
			}
		}	
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		ct();
		if (check == 0){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}
