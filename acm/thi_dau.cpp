#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string ans = ""; int sum = 0; int sub = 0;
    int n; cin >> n;
    while(n--){
        string s; cin >> s;
        int cursum = 0, cursub = 0;
        for(int i = 1; i <= 4; i++){
            int x, y; cin >> x >> y;
            if (y != 0){
                cursum += y;
                cursum += 20 * (x - 1);
                cursub += 1;
            } 
        }
        if ((cursub > sub) || (cursub == sub && cursum < sum)){
            ans = s;
            sum = cursum;
            sub = cursub;
        }
    }
    cout << ans << " " << sub << " "<< sum;
}
/*
Solution:
– Từ dữ liệu đưa vào của mỗi đội, tính số bài đúng và số điểm phạt, cập nhật kết quả tối ưu và lưu thông tin đội mạnh nhất.
*/