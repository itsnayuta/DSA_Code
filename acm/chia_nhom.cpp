#include <iostream>
using namespace std;
int n, k, sum, a[15];
int f[10003];
int main(){
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if (sum & k != 0){
        cout << 0;
        return 0;
    }
    if (k == 1) {
        cout << 1;
        return 0;
    }
    memset(f, 0, sizeof(f));
    for (int i = 10003; i >=0; i--){
        for (int )
    }
}