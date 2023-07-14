#include <bits/stdc++.h>
using namespace std;

bool snt[100003];

void sang() {
    memset(snt, true, sizeof(snt));
    snt[0] = false;
    snt[1] = false;
    for (int i = 2; i * i <= 100002; i++) {
        if (snt[i]) {
            for (int j = i * i; j <= 100002; j += i) {
                snt[j] = false;
            }
        }
    }
}

int main() {
    sang();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = 0;
        if (snt[n] == 1) ans++;
        for (int i = 2; i <= n / 2; i++){
            if (snt[i] == 1){
                int sum = 0;
                for (int j = i; j <= n; j++){
                    if (snt[j] == 1){
                        sum += j;
                        if (sum == n) {
                                ans++;
                            break;
                        }
                        if (sum > n) break;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
