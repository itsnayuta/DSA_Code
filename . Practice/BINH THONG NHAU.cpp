#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> a[100000];
int e[100000];
void bfs(int x, int y){
	queue<int> qe;
	qe.push(x);
	e[x] = 1;
	while(!qe.empty()) {
		int v = qe.front();
		if(v == y) {
			cout << 1 << endl;
			return;
		}
		qe.pop();
		for (int t : a[v]) {
			if (e[t] == 0){
				qe.push(t);
				e[t] = 1;
			}
		}
	}
	cout << 0 << endl;
}
int main(){
	int q; cin >> q;
	while(q--){
		int x, y, z;
		cin >> x >> y >> z;
		if (z == 1){
			a[x].push_back(y);
			a[y].push_back(x);	
		}
		else {
			memset(e, 0, sizeof(e));
			bfs(x, y);
		}
	}
}
