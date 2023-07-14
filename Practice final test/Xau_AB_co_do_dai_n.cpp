#include <bits/stdc++.h>
using namespace std;
int n;
void ct(int cnt, string s){
    if (cnt == n){
        cout << s << " ";
        return;
    }
    ct(cnt + 1, s + "A");
    ct(cnt + 1, s + "B");
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        ct(0, "");
        cout << endl;
    }
}