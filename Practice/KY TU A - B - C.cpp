#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[1005], f[1005];
void init(){
	a[1] = 'A';
	a[2] = 'B';
	a[3] = 'C';
}
map<char, int> mp;
void Try(int i){
	for (int j = 1; j <= 3; j++){
		f[i] = a[j];
		mp[f[i]]++;
		if (i == m){
			if (mp[a[1]] > 0 && mp[a[2]] > 0 && mp[a[3]] > 0 && mp[a[1]] <= mp[a[2]] && mp[a[2]] <= mp[a[3]]){
				for (int k = 1; k <= m; k++){
					cout << f[k];
				}
				cout << endl;
			}
		}
		else Try(i + 1);
		mp[f[i]]--;
	}
}
int main(){
	init();
	cin >> n;
	for (int i = 3; i <= n; i++){
		m = i;
		Try(1);
	}	
}
