#include <bits/stdc++.h>
using namespace std;
int n;
int a[103];

void print(int i){
	string s = "[";
	for (int j = 0; j < n - i + 1; j++){
		s += to_string(a[j]) + " ";
	}
	s.pop_back();
	s += "]";
	cout << s << endl;
}
void ct(int i){
	print(i);
	if (i == n) return;
	
	for (int j = 0; j < n - i; j++){
		a[j] = a[j] + a[j + 1];
	}
	ct(i + 1);
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		ct(1);
	}
}
