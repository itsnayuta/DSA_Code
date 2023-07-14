#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int a[203];
int main(){
    int t; cin >> t;
    while(t--){
        cin >> s >> k;
        set<string> st;
        int n = s.size();
        for (int i = 1; i <= k; i++){
            a[i] = i;
        }
        while(1){
            string tmp = "";
            for (int i = 1; i <= k; i++){
                tmp += s[a[i] - 1];
            }
            st.insert(tmp);
            int i = k;
            while(i > 0 && a[i] == n - k  + i)
                i--;
            if (i == 0){
                break;
            }
            else {
                a[i]++;
                for (int j = i + 1; j <= k; j++){
                    a[j] = a[i] - i + j;
                }
            }
        }
        for (auto x : st){
            cout << x << endl;
        }
    }
}