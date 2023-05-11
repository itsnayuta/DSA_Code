#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		long long f[n + 3];
		memset(f, 0, sizeof(f));

		long long tmp = 0;
		for (int i = 1; i <= 3; i++){
			f[i] = tmp + 1;
			tmp += f[i];
		}

		for (int i = 4; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				f[i] += f[i - j];
			}
		}

		cout << f[n] << endl;
	}

}
