#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> ke;
int vs[100005];
int f[100005];

void bfs(){
	queue<int> q;
	q.push(1);
	vs[1] = 1;
	int top;
	int res = -1;
	while(!q.empty()){
		top = q.front();
		q.pop();
		
		for(int v : ke[top]){
			if(vs[v] == 0)
			{
				vs[v] = 1;
				f[v] = f[top] + 1;
				res = max(res, f[v]);
				q.push(v);
			}
		}
	}
	
	cout << res << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		ke.assign(n+1, {});
		memset(vs, 0, sizeof(vs));
		memset(f, 0, sizeof(f));
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			ke[x].push_back(y);
		}
		f[1] = 0;
		bfs();
	}
}

