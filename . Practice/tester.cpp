//Dijkstra
int n, s, a[100][100], d[100], e[100], vs[100];
void Dijkstra(int s){
	int u, v;
	for (v=1; v<= n; v++){
		d[v]= a[s][v]; e[v]=s;
	}
	d[s]= 0; e[s] = 0; vs[s]= 1;
	while (1){
		int u= 0,
		min= 32767;
		for (v=1; v<= n; v++){
			if (vs[v]==0 && d[v]< min){
				u= v; min= d[v];
			}
		} 
			
		if (u == 0) return;
		vs[u]= 1;
		for (v=1; v<=n; v++){
			if (vs[v]== 0 && d[v]> d[u]+a[u][v]) {
				d[v]= d[u] + a[u][v];
				e[v] = u;
			}
		}
	}
}

//Bellmen
int n, s, a[100][100], d[100], e[100];
int BellmanFord(int s){
	int dem, u, v;
	for (v=1; v<= n; v++){
		d[v]= a[s][v]; e[v]=s;
	}
	d[s]= 0; e[s] = 0;
	int ok= 0;
	for (dem=1; dem<= n-1; dem++){ 
		int ok= 1;
		for (v=1; v<=n; v++){
			for (u=1; u<=n; u++){
				if (d[v] > d[u] + a[u][v]){
					d[v] = d[u] + a[u][v];
					e[v] = u;
					ok= 0;
				}
			}	
			if (ok == 1) return(1);
		}	
	}
	return(0);
}

// DFS
int a[100][100], n, u, vs[100], e[100], s[100];
void DFS(int u){
	int top= 1; s[top]= u; vs[u] = 1;
	while (top > 0){ 
		int v = s[top]; 
		int ok = 1;
		for (int i= 1; i<=n; i++)
			if (vs[i]==0 && a[v][i]==1) { 
				top++; 
				s[top] = i;
				vs[i] = 1; e[i]= v; ok = 0; 
				break;
			}
		if (ok == 1) top--;
	}		
}

// BFS
int a[100][100], n, u, vs[100], e[100], q[100];
void BFS(int u){ 
	int v, dq = 1, cq = 0;
	cq++; q[cq] = u; vs[u] = 1;
	while (dq <= cq){ 
		v = q[dq];
		dq++;
		cout << v << ” ”;
		for (int i= 1; i<=n; i++)
		if (vs[i]==0 && a[v][i]==1){
			cq++;
			q[cq] = i; vs[i] = 1; e[i]= v;
		}
	}
}

