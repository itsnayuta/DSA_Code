#include <bits/stdc++.h>
using namespace std;
string s;
int n;

void ct(){
	vector<long long> v(n + 1, 0);
	v[0] = 1;
	s = "." + s;
	for (int i = 1; i <= n; i++){
		if (v[i] == '0'){
			if (i == 1 || (s[i - 1] != '1' && s[i - 1] != '2')){
				cout << 0 << endl;
				return;
			}
			v[i] = v[i - 2];
		}
		else {
			v[i] = v[i - 1];
			if ((s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) && i >= 2){
				v[i] += v[i - 2];
			}
		}
	}
	cout << v[n] << endl;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		ct();
	}		
}
/*
#include <iostream>
#include <string>

using namespace std;

int numDecodings(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') {
        return 0;
    }

    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;
        if (s[i-1] != '0') {
            dp[i] = dp[i-1];
        }
        int twoDigits = stoi(s.substr(i-2, 2));
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i-2];
        }
    }

    return dp[n];
}

int main() {
    int t; cin >> t;
    while(t--){
    	string encodedMessage;
    	cin >> encodedMessage;

    	int numWays = numDecodings(encodedMessage);

    	cout << numWays << endl;
	}
}
*/
