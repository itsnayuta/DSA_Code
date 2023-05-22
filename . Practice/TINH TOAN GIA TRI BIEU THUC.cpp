#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;

void Hauto(){
	stack<long long> st;
	for (int i = 0; i < n; i++){
		if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
			long long a = st.top();
			st.pop();
			long long b = st.top();
			st.pop();
			
			if (v[i] == "+") st.push(a + b);
			else if (v[i] == "-") st.push(b - a);
			else if (v[i] == "*") st.push(b * a);
			else st.push(b / a);
		}
		else {
			st.push(stoi(v[i]));
		}
	}
	cout << st.top() << endl;
}

void Tiento(){
	stack<long long> st;
	for (int i = n - 1; i >= 0; i--){
		if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
			long long a = st.top();
			st.pop();
			long long b = st.top();
			st.pop();
			
			if (v[i] == "+") st.push(a + b);
			else if (v[i] == "-") st.push(a - b);
			else if (v[i] == "*") st.push(b * a);
			else st.push(a / b);
		}
		else {
			st.push(stoi(v[i]));
		}n#include<bits/stdc++.h>
using namespace std;
int n;
vector<string> v;

void Hauto(){
	stack<long long> st;
	for (int i = 0; i < n; i++){
		if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
			long long a = st.top();
			st.pop();
			long long b = st.top();
			st.pop();
			
			if (v[i] == "+") st.push(a + b);
			else if (v[i] == "-") st.push(b - a);
			else if (v[i] == "*") st.push(b * a);
			else st.push(b / a);
		}
		else {
			st.push(stoi(v[i]));
		}
	}
	cout << st.top() << endl;
}

void Tiento(){
	stack<long long> st;
	for (int i = n - 1; i >= 0; i--){
		if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/"){
			long long a = st.top();
			st.pop();
			long long b = st.top();
			st.pop();
			
			if (v[i] == "+") st.push(a + b);
			else if (v[i] == "-") st.push(a - b);
			else if (v[i] == "*") st.push(b * a);
			else st.push(a / b);
		}
		else {
			st.push(stoi(v[i]));
		}
	}
	cout << st.top() << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			v.push_back(s);
		}
		if (v[0] == "+" || v[0] == "-" || v[0] == "*" || v[0] == "/")
			Tiento();
		else Hauto();	
	}
}
	}
	cout << st.top() << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++){
			string s; cin >> s;
			v.push_back(s);
		}
		if (v[0] == "+" || v[0] == "-" || v[0] == "*" || v[0] == "/")
			Tiento();
		else Hauto();	
	}
}
