#include<bits/stdc++.h>
using namespace std;

void ct(string s){
	int n = s.size();
	stack<string> st;
	string tmp;
	stringstream ss(s);
	while(ss >> tmp){
		st.push(tmp);
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}

int main(){
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string s; getline(cin, s);
		ct(s);
		cout << endl;
	}
}


