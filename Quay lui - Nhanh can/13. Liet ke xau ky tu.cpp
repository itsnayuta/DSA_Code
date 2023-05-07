#include <iostream>
#include <string>
using namespace std;

int n, k;
string s;

void ct(int m, int a)
{
    if (m > k){
        cout << s << endl;
        return;
    }
    for (int i = a; i < n; i++){
        s[m - 1] = i + 'A';
        ct(m + 1, i);
    }
}

int main()
{
    char c;
    cin >> c >> k;
    n = c - 'A' + 1;
    s.resize(k);
    ct(1, 0);
    return 0;
}


