#include<bits/stdc++.h>
using namespace std;

int prio(char c)
{
	if(c == '*' || c == '/')
		return 3;
	if(c == '+' || c == '-')
		return 2;
	else return 1;
}

long long tinh(long long a, long long b, string x)
{
	if(x == "+")	return a+b;
	else if(x == "-")	return a-b;
	else if(x == "*")	return a*b;
	else return a/b;
}

long long trans(string s)
{
	long long res = 0;
	for(int i = 0; i< s.size(); i++)
	{
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

void solve(string s)
{
	vector<string> v;
	stack<char> st;
	//biendoivehauto
	for(int i = 0; i< s.size(); i++)
	{
		if(s[i] == '(')
			st.push(s[i]);
		else if(isdigit(s[i]))
		{
			string res = "";
			while(i< s.size() && isdigit(s[i]))
			{
				res += s[i];
				i++;
			}
			i--;
			v.push_back(res);
		}
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				v.push_back(string(1, st.top()));
				st.pop();
			}
			st.pop();
		}
		else
		{
			while(!st.empty() && prio(st.top()) >= prio(s[i]))
			{
				v.push_back(string(1, st.top()));
				st.pop();
			}
			
			st.push(s[i]);
		}
	}
	
	while (!st.empty()) 
	{
        v.push_back(string(1, st.top()));
        st.pop();
    }
    
    //tinhtoan
    
    stack<long long> st2;
    
    for(int i = 0; i< v.size(); i++)
    {
    	if(v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/")
    	{
    		long long t1 = st2.top(); st2.pop();
    		long long t2 = st2.top(); st2.pop();
    		st2.push(tinh(t2, t1, v[i]));
		}
		else st2.push(trans(v[i]));
	}
	
	cout << st2.top();
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s; cin >> s;
		solve(s);
		cout << endl;
	}
}
