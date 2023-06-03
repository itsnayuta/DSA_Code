
#include <bits/stdc++.h>
using namespace std;
int n, s, t;
int a[1003][1003];
int vs[1003];
int d[1003], p[1003];


void Dijkstra(){
	int u, v;
	cin >> s >> t;
	for (int v = 1; v <= n; v++){
		d[v] = a[v][s];
		if (a[v][s] == 1000) p[v] = -1;
		else p[v] = s;
	}
	d[s] = 0; p[s] = 0; vs[s] = 1;
	cout << s << " ";
	while(!vs[t]){
		int min = INT_MAX;
		for (int v = 1; v <= n; v++){
			if (!vs[v] && d[v] < min){
				u = v;
				min = d[v];
			}
		}
		vs[u] = 1;
		cout << u << " ";
		if(!vs[t]){
			for (int v = 1; v <= n; v++){
				if (!vs[v] && d[v] > d[u] + a[u][v]){
					d[v] = d[u] + a[u][v];
					p[v] = u;
				}
			}
		}
	}
	cout << endl << d[t];
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++){
				cin >> a[i][j];
				if (a[i][j] == -1) a[i][j] = 1000;
			}
				
			
		Dijkstra();
	}
}

/*
0 20 5 17 -1 -1 -1
20 0 -1 1 -1 -1 1 
5 -1 0 25 3 10 -1
17 1 25 0 15 -1 -1
-1 -1 3 15 0 1 -1 
-1 -1 10 -1 1 0 1 
-1 1 -1 -1 -1 1 0

0 10 15 20 -1 1 -1
-1 0 3 -1 -1 -1 30
-1 -1 0 25 3 -1 45
-1 10 25 0 35 -1 -1
-1 2 3 -1 0 -1 3
-1 -1 1 1 -1 0 25
-1 1 -1 30 -1 1 0
Mo ta thuat toan:
- d[i] luu do dai ngan nhat di tu s den i
- p[i] luu lai dinh dung truoc i
Can tim duong di ngan nhat tu dinh s den dinh t

void Dijkstra(int s){
	int u, v;
	for (int v= 1; v <= n; v++){
		d[v] = a[s][v];
		if(d[v] == 1000) p[v] = -1;
		else p[v] = s;
		vs[v] = 0;
	}
	p[s] = 0; d[s] = 0; vs[s] = 1;
	for (int i = 1; i <= n; i++){
		tim dinh u sao cho d[u] = min {d[v] | v = 1 -> n}
	Neu khong tim duoc thi break;
	vs[u] = 1;
	for (int v = 1; v <= n; v++){
		if (vs[v] = 0 && d[v] > d[u] + a[u][v]) {
			d[v] = d[u] + a[u][v];
			p[v] = u;
		}
	}
	Tra lai ket qua dua vao d[] va p[];
*/ 


