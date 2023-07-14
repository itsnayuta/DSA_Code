#include <bits/stdc++.h>
using namespace std;
vector<int> a;
string s;

void ct(){
    int n = s.size();
    int i = n - 2;
    while(n >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0){
        cout << "BIGGEST" << endl;
        return;
    }
    int h = n - 1;
    while(s[h] <= s[i])
        h--;
    swap(s[h], s[i]);
    int l = i + 1, r = n - 1;
    while(l <= r){
        swap(s[l], s[r]);
        l++; r--;
    }
    cout << s << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int test; cin >> test;
        cin >> s;
        cout << test << " ";
        ct();
    }
}
