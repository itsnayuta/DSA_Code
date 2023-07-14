#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int maxx = *max_element(a, a + n);
        int minn = *min_element(a, a + n);
        cout << (maxx - minn) * 2 << endl;
    }
}
/*
– Đề này viết hơi khó hiểu, nhưng có thể tạm giải thích như thế này:

– giả sử Michael dựng xe ở điểm A và anh ta sẽ đi hết tất cả các cửa hàng, ví dụ đầu tiên anh ta đứng ở A, sau đó anh ta đi đến các của hàng theo đường đến cửa hàng 1. (cửa hàng 2, 1 theo trong hình minh họa).

– Xong, anh ta phải đi đến cửa hàng 3 4 5, rồi quay về điểm đỗ xe.

– Dễ dàng nhận thấy anh ta đỗ xe ở đâu thì đường đi mà anh ta đi qua cũng như nhau, không thay đổi về khoảng cách.

Vậy nên ta chỉ cần tính khoảng cách của 2 cửa hàng xa nhất, ở đây tính theo tọa độ nên chỉ cần tìm min và max. Anh ta có 2 lượt đi, 1 là đi đến cửa hàng, 2 là đi về nên phải x2 khoảng cách.

Tổng quát: (Max(x[i])-Min(x[i]))*2 là kết quả bài toán.*/