#include <bits/stdc++.h>
using namespace std;
vector<string> a;
int n;

void ct(){
    map<string, int> mp;
    for(auto x : a){
        mp[x]++;
    }
    for (int i = 0; i < n; i++){
        for (int j = 1; j < a[i].size(); j++){
            string s = a[i].substr(0 , j);
            if (mp[s] > 0) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--){
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ct();
    }
}
/*
Solution:
Mình sẽ hướng dẫn các bạn làm bài này bằng cách thô nhất. với mỗi test độ phức tạp sẽ là O(10*N log2 N)

Ý tưởng: bạn nhập các SĐT ở dạng xâu, và đầu tiên bạn sẽ sắp xếp các xâu đó.

với mỗi xâu A[i] bạn sẽ dùng chặt nhị phân tìm xem có xâu nào giống xâu S ko, với S là xâu được cắt ra từ xâu A[i] (từ A[i][1]->a[i][j] , với j=2..length(a[i])).

Nếu chặt nhị phân mà tìm thấy tức là nó không nhất quán, và ngược lại.
*/