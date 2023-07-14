#include <bits/stdc++.h>
using namespace std;
int n;
void ct(int i, string s){
    if (i == n - 1 && s[i] == '6'){
        cout << s << endl;
        return;

    }
        if (s[i] == '8')
            ct(i + 1, s + "6");
        if (s[i] == '6' && s[i - 1] == '6')
            ct(i + 1, s + "8");
        if (s[i] == '6' && s[i - 1] == '8') 
            ct(i + 1, s + "6");
}
int main(){
    cin >> n;
    ct(1, "86");
}