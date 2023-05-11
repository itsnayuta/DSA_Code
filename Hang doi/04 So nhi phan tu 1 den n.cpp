#include<bits/stdc++.h>
using namespace std;
void ct(int n){
	queue<string> q;
	q.push("1");
	while(n--){
		string a = q.front();
		cout << a << " ";
		q.pop();
		q.push(a + "0");
		q.push(a + "1");
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		ct(n);
		cout << endl;
	}
	
}

