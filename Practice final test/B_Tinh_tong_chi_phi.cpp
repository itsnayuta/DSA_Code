#include<bits/stdc++.h>
using namespace std;
int n, k;

int main(){
    cin >> n >> k;
    priority_queue<int,vector<int>, greater<int>> qe;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        qe.push(a);
    }
    int cnt = 0;
    while(qe.size() != 1){
        if (qe.size() >= k){
            int sum = 0;
            for (int i = 1; i <= k; i++){
                if (i == k) cnt += qe.top();
                if (i == 1) cnt -= qe.top();
                sum += qe.top();
                qe.pop();
            }

            qe.push(sum);
            cnt ++;
        }
        else {
            int sum = 0;
            cnt -= qe.top();
            for (int i = 1; i <= k; i++){
                if (qe.size() == 1){
                    cnt += qe.top();
                }
                sum += qe.top();
                qe.pop();    
            }
        }
    }
    cout << qe.top() << endl;
    cout << cnt;
}