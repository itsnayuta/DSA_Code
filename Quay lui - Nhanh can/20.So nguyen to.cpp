#include<bits/stdc++.h>
using namespace std;
int n, p, s;

vector<int> check(201, 1), pr;
vector<vector<int>> res;
void sang(){
	for(int i = 2; i <= 200; i++)
		for(int j = i * i; j <= 200; j += i)
			check[j] = 0;
			
	for(int i = 2; i <= 200; i++){
		if(check[i] == 1)
			pr.push_back(i);
	}
}

void Try(int pos, int sum, vector<int> v){
	if(v.size() == n){
		if(sum == s)
			res.push_back(v);
			
		return;
	}
	
	for(int i = pos; i < pr.size(); i++){
		if(pr[i] + sum <= s){
			v.push_back(pr[i]);
			Try(i+1, pr[i] + sum, v);
			v.pop_back();
		}
	}
}

int main(){
	sang();
	int t;
	cin >> t;
	while(t--){
		res.clear();
		cin >> n >> p >> s;
		int pos = 0;
		for(int i = 0; i < pr.size(); i++){
			if(pr[i] > p){
				pos = i;
				break;
			}
		}
		Try(pos, 0, {});
		cout << res.size() << endl;
		sort(res.begin(), res.end());
		for(auto x : res){
			for(auto t : x)
				cout << t << " ";
			cout << endl;
		}
	}
}


