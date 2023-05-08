#include <bits/stdc++.h>
using namespace std;
string s;


void ct() {
	stack<int> st;
	for (int i = 0; i < s.size(); i++){
		int k = s[i] - '0';
		if(k >= 0 && k <= 9){
			st.push(k);
		}
		else {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			
			if (s[i] == '+' ) st.push(a + b);
			else if (s[i] == '-' ) st.push(b - a);
			else if (s[i] == '*' ) st.push(a * b);
			else if (s[i] == '/' ) st.push(b / a);
		}		
	}
	
	cout << st.top() << endl;
}
  
int main() {
	int t; cin >> t;
	while(t--){
		cin >> s;
		ct();
	}
}



