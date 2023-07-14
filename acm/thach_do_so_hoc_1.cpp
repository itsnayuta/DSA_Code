#include <bits/stdc++.h>
using namespace std;
char a[1003][1003];
int n, ans;
void ct(int i, int j){
    if (i == n && j == n){
        ans += 1;
        return;
    }
    if (i < n - 1 && a[i + 1][j] == '.') ct(i + 1, j);
    if (j < n -1 && a[i][j + 1] == '.') ct(i, j + 1);

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    
    ct(0, 0);
    cout << ans;
}
