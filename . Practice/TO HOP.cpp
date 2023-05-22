#include<bits/stdc++.h>
using namespace std;
int n, k, check;
string s;
vector<char> v;

int main(){
	int t; cin >> t;
	while(t--){
		v.clear();
		cin >> s >> k;
		set<string > st;
		int n = s.size();
		int a[n + 1];
		for(int i = 1; i <= n; i++) 
			a[i] = i;
		while(1){
			string tmp = "";
		for (int i = 1; i <= k; i++) {
			tmp += s[a[i] - 1];
		}
		st.insert(tmp);
		int i = k;
		while(i > 0 && a[i] == n - k + i)
			i--;
		if (i == 0) {
			for (auto x : st){
				cout << x << endl;
			}
			break;
		}
		
		a[i]++;
		for (int j = i + 1; j <= n; j++)
			a[j] = a[i] - i + j;
		}	
	}
}
