#include<bits/stdc++.h>
using namespace std;
int n, check;
queue<string> q;

void Try(string s){
    long long f = 0;
    for (int i = 0; i < s.size(); i++){
        f = f * 10 + (s[i] - '0');
        f %= n;
    }
    if (f == 0){ 
        while(!q.empty()) 
            q.pop();
        return;
    }

    q.push(s + "0");
    q.push(s + "9");

    string tmp = q.front();
    q.pop();    
    Try(tmp);
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        string s = "9";
        Try(s);
    }
}