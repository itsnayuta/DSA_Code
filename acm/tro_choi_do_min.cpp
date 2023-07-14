#include <bits/stdc++.h>
using namespace std;
int n, m;
char  a[200][200];

char  ct(int i, int j){
    int cnt = 0;
    if (a[i - 1][j - 1] == '*') cnt++;
    if (a[i - 1][j] == '*') cnt++;
    if (a[i - 1][j + 1] == '*') cnt++;
    if (a[i][j - 1] == '*') cnt++;
    if (a[i][j + 1] == '*') cnt++;
    if (a[i + 1][j - 1] == '*') cnt++;
    if (a[i + 1][j] == '*') cnt++;
    if (a[i + 1][j + 1] == '*') cnt++;
    return char(cnt + '0');
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n >> m){
        if (n == 0 && m == 0) return 0;
        for (int i = 0; i <= n + 1; i++){
            a[i][0] = '.';
            a[i][m + 1] = '.';
        }
        for (int i = 0; i <= m + 1; i++){
            a[0][i] = '.';
            a[n + 1][i] = '.';
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] == '.'){
                    a[i][j] = ct(i, j);
                }
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}
