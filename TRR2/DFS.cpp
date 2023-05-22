#include <bits/stdc++.h>
using namespace std;
vector<int> E[103];
int visited[103];
int ans[103];
int v, e;
void dfs1(int u) {
	visited[u] = 1;
	cout << u << " ";
	for (auto x : E[u]) {
		if (visited[x] == 0){
			visited[x] = 1;
			dfs1(x);
		}
	}
}
void dfs2(int u){
	visited[u] = 1;
	for (auto x : E[u]){
		if(visited[x] == 0){
			visited[x] = 1;
			ans[x] = u; 
			dfs2(x);
		}
	}
}
void waydfs(int u, int v){
	dfs2(u);
	vector<int> res;
	if (visited[v] == 1){ 
		int t = v;
		while (t > 0) {
			res.push_back(t);
			t = ans[t];
		}
		for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
	}
	else cout << "-1";
	cout << endl;
}
int main(){
	cout << "Nhap so bo test: " << endl; 
	int t; cin >> t;
	for (int p = 0; p < t; p++){
		cout << "----------------------------------------------------" << endl;
		cout << "Test " << p + 1<< ":" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Chon kieu do thi:" << endl;
		cout << "1. Do thi vo huong" << endl;
		cout << "2. Do thi co huong" << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Lua chon cua ban: " << endl;
		int rq; cin >> rq;
		cout << "----------------------------------------------------" << endl;
		cout << "Nhap so dinh cua do thi: " << endl;
 		cin >> v;
 		cout << "----------------------------------------------------" << endl;
		cout << "Nhap so canh cua do thi: " << endl;
		cin >> e;
		cout << "----------------------------------------------------" << endl;
		for (int i = 0; i < e; i++)	
			E[i].clear();
		cout << "Nhap danh sach cach cua do thi: " << endl;
		if (rq == 1){
			for (int i = 0; i < e; i++){
				int x, y; cin >> x >> y;
				E[x].push_back(y);
				E[y].push_back(x);
			}
		}
		else {
			for (int i = 0; i < e; i++){
				int x, y; cin >> x >> y;
				E[x].push_back(y);
			}
		}
	
		int check = 0;
		while(check == 0){
			cout << "----------------------------------------------------" << endl;
			cout << "Hay chon yeu cau can thuc hien: " << endl;
			cout << "1. Tim DFS cua do thi." << endl;
			cout << "2. Tim duong di bang dfs tu dinh u sang dinh v." << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Lua chon cua ban: " << endl;
			int request; cin >> request;
			if (request == 1){
				memset(visited, 0, v + 1);
				cout << "----------------------------------------------------" << endl;
				cout << "Chon dinh bat dau: ";
				int u; cin >> u;
				cout << "----------------------------------------------------" << endl;
				cout << "Ket qua: " << endl;
				dfs1(u);
				cout << endl;
			}
			else if (request == 2){
				cout << "----------------------------------------------------" << endl;
				cout << "Hay nhap lan luot dinh u va dinh v: ";
				int u, v; cin >> u >> v;
				memset(visited, 0, v + 1);
				memset(ans, 0, v + 1);
				cout << "----------------------------------------------------" << endl;
				cout << "Ket qua: " << endl;
				waydfs(u, v);
			}
			cout << "----------------------------------------------------" << endl;
			cout << "Hay chon yeu cau can thuc hien: " << endl;
			cout << "1. Chon lai yeu cau." << endl;
			cout << "2. Bat dau voi do thi moi." << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Lua chon cua ban: ";
			cin >> request;
			if (request == 1) continue;
			else check = 1;
		}
	}
}
