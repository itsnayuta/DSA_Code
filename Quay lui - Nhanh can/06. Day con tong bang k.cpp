#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> ans;
int n, k, check;

void xl(){
    long long sum = 0;
    for (int i = 0; i < ans.size(); i++){
        sum += v[ans[i]];
    }

    if (sum == k) {
        check = 1;
        cout << "[";
        for (int i = 0; i < ans.size(); i++){
            cout << v[ans[i]];
            if (i  != ans.size() - 1) cout << " ";
        }
        cout << "]";
        cout << " ";
    }
}
void ct(int i){
    for (int j = 1; j >= 0; j--){
        if (j == 1) ans.push_back(i);
        if (i == n - 1) xl();
        else ct(i + 1);

        if (j == 1) ans.pop_back();
    } 

}
int main(){
    int t; cin >> t;
    while(t--){
        ans.clear();
        check = 0;
        cin >> n >> k;
        v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        ct(0);
        if (check == 0) cout << -1 << endl;
        else cout << endl;
    }

}
