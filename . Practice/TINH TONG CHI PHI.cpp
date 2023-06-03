#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;
int main(){
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	priority_queue<int> q;
	for (auto x : a){
		q.push(x);
	}
	while(q.size() != 1){
		int i = k;
		int res = 0;
		if (q.size() >= k){
			while(i--){
				int p = q.top();
				q.pop();
				res += p;
			}
			q.push(res);
		}
		else {
			while(!q.empty()){
				res += q.top();
				q.pop();
			}
			q.push(res);
		}
	}
	cout << q.top() << endl;
}
