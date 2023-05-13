#include <bits/stdc++>
using namespace std;

bool isCheck(vector<int>& inorder) {
    int n = inorder.size();

    for (int i = 1; i < n; i++) {
        if (inorder[i] <= inorder[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		if (isCheck(v) == true) cout << 1 << endl;
		else cout << 0 << endl;
	}
}

