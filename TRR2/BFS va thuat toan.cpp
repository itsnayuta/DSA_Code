// BFS

#include <bits/stdc++.h>
using namespace std;
int n, u;
int a[1003][1003];
int vs[1003];

void BFS(int u){
	queue<int> q;
	q.push(u);
	vs[u] = 1;
	cout << u << " ";
	while(!q.empty()){
		int i = q.front();
		q.pop();
		for(int j = 1; j <= n + 1; j++){
			if (a[i][j] == 1 && vs[j] == 0){
				vs[j] = 1;
				cout << j << " ";
				q.push(j);
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n >> u;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		memset(vs, 0, sizeof(vs));
		BFS(u);
		cout << endl;
	}
}
/*
0 1 0 0 1 0 0 1 0 1 
1 0 1 1 0 1 0 0 0 0 
0 1 0 1 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
1 0 0 0 0 1 1 1 1 1
0 1 0 0 1 0 0 0 0 0 
0 0 0 0 1 0 0 1 1 1 
1 0 0 0 1 0 1 0 0 1 
0 0 0 0 1 0 1 0 0 0
1 0 0 0 1 0 1 1 0 0 

Mo ta thuat toan:
Buoc 1: <Khoi tao>
Khoi tao queue = rong, vs[u] = 1, queue.push(u)

Buoc 2: <Lap>
while(!queue.empty()){
	int i = qe.front();
	qeue.pop();
	for reach j thuoc ke(i) do:
		if (vs[j] == 0){
			vs[j] = 1;
			queue.push(j);
		}
	}
}

Buoc 3: <Tra ve ket qua>
Return ve <tap dinh da duyet>
*/

