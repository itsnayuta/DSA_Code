#include <bits/stdc++.h>
using namespace std;
// cai tui
int a[103], c[103];
int n, s;
int main(){
	cin >> n >> s;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    int f[103][103];
    memset(f, 0, sizeof(f));
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j =1; j <= s; j++){
            f[i][j] = f[i - 1][j];
            if (j >= a[i]){
                f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + c[i]);
            }
            if (ans < f[i][j]) ans = f[i][j];
        }
        
    }
    cout << ans;
}
