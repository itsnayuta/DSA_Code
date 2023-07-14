#include <bits/stdc++.h>
using namespace std;
vector<int> a[100003];
int e[100003];

int bfs(int u,int v){
    memset(e, 0, sizeof(e));
	queue<int> qe;
    qe.push(u);
	e[u] = 1;
	while (!qe.empty()) {
		int x = qe.front();
		if (x == v) return 1;
		qe.pop();
		for (int t : a[x]) {
			if (e[t] == 0){
				qe.push(t);
				e[t] = 1;
			}
		}
	}
    return 0;
}
int main(){
    int t; cin >> t;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        if (z == 1){
            a[x].push_back(y);
            a[y].push_back(x);
        }
        else {
            cout << bfs(x, y) << endl;
        }
    }
}