// tag: backtracking
#include <bits/stdc++.h>
using namespace std;
string s;
void ct(){
    while(s.size() > 1){
        int sum = 0;
        for (int i = 0; i < s.size(); i++){
            sum += (s[i] - '0');
        }
        s = to_string(sum);
    }
    cout << s << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        cin >> s;
        ct();
    }
}
