#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	int n = s.size();
	stack<int> st;
	
	for(int i = 0; i< n; i++)
	{
		if(s[i] == '(')
			st.push(i);
		else
		{
			if(!st.empty() && s[st.top()] == '(') 
				st.pop();
			else 
				st.push(i);
		}
	}
	
	vector<int> v;
	
	if(st.empty())
	{
		cout << n;
		return;
	}
	else
	{
		while(!st.empty())
		{
			int tmp = st.top();
			v.push_back(tmp);
			st.pop();
		}
		
		sort(v.begin(), v.end());
		
		int res = 0;
		
		for(int i = 1; i< v.size(); i++)
		{
			res = max(res, v[i] - v[i-1] - 1);
		}
		
		res = max(res, v[0] - 0);
		res = max(res, n-1 - v[v.size()-1]);
		cout << res;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		solve(s);
		cout << endl;
	}
}


