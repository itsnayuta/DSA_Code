#include <bits/stdc++.h>
using namespace std;
int n, a[100003], ans[100003];
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		stack<int> st;
		
		for (int i = n - 1; i >= 0; i--){
			if (!st.empty() && st.top() < a[i])
				st.pop();
			if (st.empty()) ans[i] = -1;
			else ans[i] = st.top();
			st.push(a[i]);
		}
		
		for (int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
