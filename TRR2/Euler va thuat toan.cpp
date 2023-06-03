// Euler

#include <bits/stdc++.h>
using namespace std;
int n;
int a[1003][1003];

void Euler(){
	vector<int> CE;
	stack<int> st;
	st.push(10);
	while(!st.empty()){
		int v = st.top();
		for (int i = 1; i <= n + 1; i++){
			if (a[v][i] == 1){
				st.push(i);
				a[v][i] = a[i][v] = 0;
				break;
			}
			if (i == n + 1) {
				st.pop();
				CE.push_back(v);
			}
		}
	}
	for (int i = CE.size() - 1; i >= 0; i--)
		cout << CE[i] << " ";
	cout << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		Euler();
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
void Euler(int a[][]){
	Khoi tao mang CE de ghi chu trinh
	Khoi tao Stack st de xep cac dinh da xet
	st.push(1);
	while( !st.empty() ){
		Dinh v = st.top();
		for (int i = 1; i <= n + 1; i++) {
			if (i ke voi v) {
				st.push(i);
				xoa cach (v, i);
				break;
			}
			if (i == n + 1) {
				Lay dinh v ra khoi stack;
				day v vao trong CE
			}
		}
	}
	tu mang CE ghi ra chu trinh theo chieu nguoc lai
}
*/


