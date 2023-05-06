#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;

void ct(){
	s.resize(n);
	for (int i = 0; i < n; i++)
		s[i] = 'A';
		
	while(1) {
		cout << s << " ";
		
		int i = n - 1;
		while(i >= 0 && s[i] == 'B'){
			s[i] = 'A';
			i--;
		}
		if (i == -1) {
			cout << endl;
			return;
		}
		else {
			s[i] = 'B';
		}
	}
}
int main(){
	int t; cin>> t;
	while(t--){
		cin >> n;
		ct();
	}
}
