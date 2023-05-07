#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> s;
int a[33];

void xl(){
	string tmp;
	for (int j = 1; j <= k; j++){
		tmp += s[a[j] - 1] + " ";
	}
	cout << tmp << endl;
	return;
}
void ct(int i){
	for (int j = a[i - 1] + 1; j <= n - (k - i); j++){
		a[i] = j;
		if (i == k) xl();
		else ct(i + 1);
	}
}
int main(){
	cin >> n >> k;
	set<string> st;
	for (int i = 0; i < n; i++){
		string tmp;
		cin >> tmp;
		st.insert(tmp);
	}
	for (auto x: st){
		s.push_back(x);
	}
	n = s.size();
	a[0] = 0;
	ct(1);	
}
