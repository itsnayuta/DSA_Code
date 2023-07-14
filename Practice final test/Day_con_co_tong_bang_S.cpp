#include <bits/stdc++.h>
using namespace std;
int n, s;
int a[203];

void ct(int i, int sum){
    if (sum == s){
        cout << "YES" << endl;
        return;
    }
    if (i == n){
        cout << "NO" << endl;
        return;
    }
    for (int j = 1; j >= 0; j--){
        if (j == 1) ct(i + 1, sum + a[i]);
        else ct(i + 1, sum);
    }2
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> s;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        ct(0, 0);
    }
}