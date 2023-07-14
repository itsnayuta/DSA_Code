#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> uoc;
vs[100003];
void timUoc(int sum){
    if (sqrt(sum) * sqrt(a) == sum) uoc.push_back(sqrt(a));
    for (int i = 2; i < sqrt(a); i++){
        if (a % i == 0){
            uoc.push_back(i);
            uoc.push_back(a / i);
        }
    }
}

void ct(){
    for (int i = 0; i < uoc.size(); i++){
        int sum = 
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test; cin >> test;
    while(test--){
        int t; cin >> t;
        int n; cin >> n;
        a.resize(n);
        int sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
            vs[]
        }
        timUoc(sum);
        sort(uoc.begin(), uoc.end());
        ct();
    }
}
/*
Solution:
Bài này có dính líu một chút tới QHĐ khi bạn tính trước tổng S của mảng như code dưới đây (hoặc không cần vậy cũng được).
- Vì dãy thỏa mãn tính chất có các đoạn tổng bằng nhau nên các ước của tổng dãy là số lượng đoạn hoặc tổng từng đoạn
- Tìm các ước rồi sắp xếp nó.
- Duyệt từng ước xem dãy thỏa mãn ước nào thì in và reuturn chương trình.
(code dưới đây sử dụng các chức năng có sẵn trong thư viện)
*/