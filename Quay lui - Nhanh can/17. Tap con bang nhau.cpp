#include<bits/stdc++.h>
using namespace std;

int n, sum, check;
int a[200];

void ct(int i, int s) {
	if(i == n || check == 1 || s == sum/2) {
		if(s == sum/2)
			check = 1;
		return;
	}
	
	if(s + a[i] <= sum/2)	ct(i+1, s + a[i]);
	ct(i+1, s);
}

int main() {
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		sum = 0, check = 0;
		for(int i = 0; i< n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		
		if(sum %2 == 0) {
			ct(0, 0);
		}
		if(check == 1)	cout << "YES" << endl;
		else cout  << "NO" << endl;
	}
}


