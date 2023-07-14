// tag: dynamic programming
#include <bits/stdc++.h>
using namespace std;

int main(){
    int test; cin >> test;
    for (int t = 1; t <= test; t++){
        int n; cin >> n;
        int a[n + 1];
        a[1] = 1;
        a[2] = 2;
        for (int i = 3; i <= n; i++){
            int cnt = 1;
            for (int j = 1; j <= i / 2; j++){
                cnt += a[j];
            }
            a[i] = cnt;
        }
        cout << t << " " << a[n] << endl;
    }
}

