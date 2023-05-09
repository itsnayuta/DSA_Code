#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i< n; i++)
			cin >> a[i];
		sort(a, a+n);
		long long cnt1 = 0, cnt2 = 0;
		for(int i = 0; i< n; i++){
			if(i % 2 == 0)
				cnt1 = cnt1 * 10 + a[i];
			else cnt2 = cnt2 * 10 + a[i];
		}
		
		cout << cnt1 + cnt2 << endl;
	}
}


