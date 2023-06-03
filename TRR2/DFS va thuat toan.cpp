// DFS

#include <bits/stdc++.h>
using namespace std;
int n, u;
int a[1003][1003];
int vs[1003];

void DFS(int u){
	vs[u] = 1;
	cout << u << " ";
	for (int v = 1; v <= n; v++){
		if (a[u][v] == 1 && vs[v] == 0)
			DFS(v);
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
		DFS(u);
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
BFS(int u){
	vs[u] = 1;
	tham dinh u;
	for reach v thuoc ke(u) do:
		if (vs[v] == 0)
			DFS(v);	
	}
}
Tra ve <tap dinh da duyet>
*/

