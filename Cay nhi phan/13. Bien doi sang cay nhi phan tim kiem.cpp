#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	while(t--){
		int n, par, child; char c;
		set<int> s;
		cin >> n;
		while(n--){
			cin >> par >> child >> c;
			s.insert(par);
			s.insert(child);
		}
	
		for(int x : s)
			cout << x << " ";
		cout << endl;
	}
}

