#include<bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v;
	vector<string> ans;
	v.resize(n);
	
	for (int i = 0; i < n; i++)
		cin >> v[i];
		
	int a[n + 1];
	for (int i = 0; i < n; i++)
		a[i] = 1;
	
	for (int i = 0; i < n; i++){
		if (a[i] == 1){
			string res = "";
			res += to_string(v[i]) + " ";
			int tmp = i;
			for (int j = i + 1; j < n; j++){
				if (a[j] == 1 && v[j] > v[tmp]) {
					res += to_string(v[j]) + " ";
					a[j] = 0;
					tmp = j;
				}
			}
			ans.push_back(res);
		}
	}
	
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
}
