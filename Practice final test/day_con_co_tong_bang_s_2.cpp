#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
	int t;
	cin >> t;
	while(t--)
	{
		int n, s;
		cin >> n >> s;
		int a[n];
		for(int i = 0; i< n; i++)
			cin >> a[i];
		vector<int> v(s+1, 0);
		
		v[0] = 1;
		for(int i = 0; i<n; i++)
		{
			for(int j = s; j >=a [i]; j--)
			{
				if(v[j-a[i]] == 1)
					v[j] = 1;
			}
		}
		
		if(v[s] == 1)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

