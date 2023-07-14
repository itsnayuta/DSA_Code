#include <bits/stdc++.h>
using namespace std;
int a[13], n, m;
vector<string> ans;

void ct(){
    while(1){
        string tmp = "";
        for (int i = 1; i <= n; i++)
            tmp += to_string(a[i]) + " ";
        tmp.pop_back();
        ans.push_back(tmp);

        int i = n - 1;
        while(n > 0 && a[i] >= a[i + 1])
            i--;
        if (i == 0) return;
        int h = n;
        while(a[h] <= a[i]) h--;
        swap(a[h], a[i]);
        int l = i + 1, r = n;
        while(l <= r) {
            swap(a[l], a[r]);
            l++; r--;
        }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    ct();
    for(int i = m; i <= ans.size(); i += m){
        cout << ans[i - 1] << endl;
    }
}