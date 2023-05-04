#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int a[100000], v[100000];

void xl(){
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			cnt += v[i];
		}
	}
	if (cnt == k){
		for(int i = 0; i < n; i++){
			if (a[i] == 1) cout << v[i] << " ";
		}
		cout << endl;
		ans++;
	}
}
void ct(int i){
	for (int j = 0; j <= 1; j++){
		a[i] = j;
		if (i == n - 1) xl();
		else ct(i + 1); 
	}
}
int main() {
	cin >> n >> k;
	ans = 0;
	for (int i = 0;  i < n; i++) cin >> v[i];
	ct(0);
	cout << ans;
}

