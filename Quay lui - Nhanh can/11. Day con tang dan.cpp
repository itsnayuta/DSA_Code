#include <bits/stdc++.h>
using namespace std;
int n;
int a[23];
vector<int> ans;
vector<string> v;
void xl(){
	if(ans.size() < 2) return;
	int check = 0;
	vector<int> c = ans;
	sort(c.begin(), c.end());
	for (int j = 0; j < ans.size(); j++){
		if (ans[j] != c[j]){
			check = 1;
			break;
		}
	}
	if (check == 0){
		string tmp;
		for (auto x : ans) tmp += to_string(x) + " ";
		v.push_back(tmp);
	}	
}
void ct(int i){
	for (int j = 1; j >= 0; j--){
		if (j == 1) ans.push_back(a[i]);
		if (i == n - 1) xl();
		else ct(i + 1);
		if (j == 1) ans.pop_back();
	}
}
int main(){
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	ct(0);
	sort(v.begin(), v.end());
	for (auto x : v){
		cout << x << endl;
	}
}
