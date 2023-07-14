
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<string> a;
vector<string> ans;
void ct(){
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        v[i] = i;
    while(1){
        string s = "";
        for (int i = 1; i <= k; i++){
            s += a[v[i] - 1] + " ";
        }
        s.pop_back();
        ans.push_back(s);

        int i = k;
        while(i > 0 && v[i] == n - k + i)
            i--;
        if (i == 0) return;
        v[i]++;
        for (int j = i + 1; j <= k; j++){
            v[j] = v[i] - i + j;
        }
    }
}
int main(){
    cin >> n >> k;
    set<string> st;
    for (int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        st.insert(tmp);
    }
    for (auto x : st){
        a.push_back(x);
    }
    n = st.size();
    ct();
    sort(ans.begin(), ans.end());
    for (auto x : ans){
        cout << x << endl;
    }
}