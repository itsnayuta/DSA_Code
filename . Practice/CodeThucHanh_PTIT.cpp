// Tinh gia tri bieu thuc tien to, hau to, trung to

// hau to 
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc(ll x, ll y, string c) {
	if (c == "+") return x + y;
	else if (c == "-") return x - y;
	else if (c == "*") return x * y;
	else return x / y;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		stack<ll>st;
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
				ll x = st.top(); st.pop();
				ll y = st.top(); st.pop();
				st.push(calc(y, x, v[i]));
				st.push(stoll(v[i]));
			}
		cout << st.top() << endl;
	}
	return 0;
}
// tien to
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc(ll x, ll y, string c) {
	if (c == "+") return x + y;
	else if (c == "-") return x - y;
	else if (c == "*") return x * y;
	else return x / y;
}
int main()
{

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		stack<ll>st;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
				ll x = st.top(); st.pop();
				ll y = st.top(); st.pop();
				st.push(calc(x, y, v[i]));
			} else {
				st.push(stoll(v[i]));
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}

// bien doi tien to - trung to

#include <bits/stdc++.h>
using namespace std;

void ct(string s) {
	int n = s.size();
	stack<string> st;
	for (int i = n - 1; i >= 0; i--) {
		string tmp = "";
		tmp += s[i];
		if (s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/') {
			string x = st.top();
			st.pop();
			string y = st.top();
			st.pop();
			string z = "(" + x + tmp + y + ")";
			st.push(z);
		}
		else {
			st.push(tmp);
		}

	}
	cout << st.top();
}
  
int main() {
	int t; cin >> t;
	while(t--){
		string s;
		cin >> s;
		ct(s);
		cout << endl;
	}
}


// bien doi tien to - hau to

#include <bits/stdc++.h>
using namespace std;

void ct(string s) {
	int n = s.size();
	stack<string> st;
	for (int i = n - 1; i >= 0; i--){
		string tmp = "";
		tmp += s[i];
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			string x = st.top();
			st.pop();
			string y = st.top();
			st.pop();
			string z = x + y + tmp;
			 st.push(z);
		} 
		else {
			st.push(tmp);
		}
		
	}
	cout << st.top();
}
int main(){
	int t; cin >> t;
	while (t--){
		string s;
		cin >> s;
		ct(s);
		cout << endl;
	}
}

//tinh gia tri bieu thuc hau to

#include <bits/stdc++.h>
using namespace std;
string s;

void ct() {
	stack<int> st;
	for (int i = 0; i < s.size(); i++){
		int k = s[i] - '0';
		if(k >= 0 && k <= 9){
			st.push(k);
		}
		else {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			
			if (s[i] == '+' ) st.push(a + b);
			else if (s[i] == '-' ) st.push(b - a);
			else if (s[i] == '*' ) st.push(a * b);
			else if (s[i] == '/' ) st.push(b / a);
		}		
	}
	
	cout << st.top() << endl;
}
  
int main() {
	int t; cin >> t;
	while(t--){
		cin >> s;
		ct();
	}
}

// tinh gia tri bieu thuc tien to

#include <bits/stdc++.h>
using namespace std;
string s;

void ct() {
	stack<int> st;
	for (int i = s.size() - 1; i >= 0; i--){
		int k = s[i] - '0';
		if(k >= 0 && k <= 9){
			st.push(k);
		}
		else {
			int a = st.top();
			st.pop();
			int b = st.top();
			st.pop();
			
			if (s[i] == '+' ) st.push(a + b);
			else if (s[i] == '-' ) st.push(a - b);
			else if (s[i] == '*' ) st.push(a * b);
			else if (s[i] == '/' ) st.push(a / b);
		}		
	}
	
	cout << st.top() << endl;
}
  
int main() {
	int t; cin >> t;
	while(t--){
		cin >> s;
		ct();
	}
}

// bien doi trung to - hau to

#include<bits/stdc++.h>
using namespace std;

int priority(char c)
{
	if(c == '^')	return 3;	
	else if(c == '*' || c == '/')
		return 2;
	else if(c == '+' || c == '-')
		return 1;
	else return 0;
}

void solve(string s)
{
	stack<char> st;
	string res = "";
	for(int i = 0; i< s.size(); i++)
	{
		if(s[i] == '(')	st.push(s[i]);
		else if(s[i] == ')')
		{
			while(!st.empty() && st.top() != '(')
			{
				res += st.top();
				st.pop();
			}
			st.pop();
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
		{
			while(!st.empty() && priority(s[i]) <= priority(st.top()))
			{
				res += st.top();
				st.pop();	
			}
			st.push(s[i]);
		}
		else res += s[i];
	}
	
	while(!st.empty())
	{
		if(st.top() != '(')	res += st.top();
		st.pop();
	}
	
	cout << res << endl;
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
	}
}


// bien doi hau to - tien to

#include<bits/stdc++.h>
using namespace std;

void solve(string s)
{
	int n = s.size();
	vector<char> v;
	stack<string> st;
	
	
	for(int i = 0; i< n; i++)
	{
		string tmp = "";
		tmp+=s[i];
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
//		if(!isdigit(s[i]))
		{
			string res = "";
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			
			res = res + tmp + b + a ;
			st.push(res);
//			cout << res << endl;
		}
		else 
			st.push(tmp);
	}
	
	cout << st.top();
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
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


// bien doi hau to - trung to

#include<bits/stdc++.h>
using namespace std;


void solve(string s)
{
	stack<string> st;
	for(int i = 0; i< s.size(); i++)
	{
		string tmp ="";
		tmp+=s[i];
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			string x = st.top();
			st.pop();
			string y = st.top();
			st.pop();
			string z = "(" + y + tmp + x + ")";
			st.push(z);
		}
		else st.push(tmp);
	}
	
	cout << st.top();
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
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

// dau ngoac

// loai bo dau ngoac
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ll t; cin>>t;
	cin.ignore();
	while(t--)
	{
		string s; getline(cin,s);
		stack<pair<ll,ll>> st;
		ll f[256]={0};
		string res="";
		for(auto x:s) 
		{
			if(x!=' ') res+=x;
		}
		ll cnt1=0,cnt2=0;
		bool ok=false;
		for(ll i=0;i<res.size();i++)
		{
			if(res[i]=='(' && i==0)
			{
				st.push({0,-1});
			}
			else
			{
				if(res[i]=='(')
				{
					if(res[i-1]=='-')
					{
						st.push({i,1});
						cnt1++;
					}
					else
					{
						st.push({i,-1});
					}
				}
				else
				{
					if(res[i]==')')
					{
						auto top=st.top();
						st.pop();
						if(top.second==1)
						{
							if(cnt2==0 && cnt1!=0) // ko co toan hang nao
							{
								f[i]=f[top.first]=-1;
							}
							else
							{
								f[i]=f[top.first]=top.second;
								cnt1--;
								cnt2--;
								ok=false;
							}
						}
						else
						{
							f[i]=f[top.first]=top.second;
						}
					}
					else if(res[i]=='+' || res[i]=='-')
					{
						if(cnt1>=1 && ok==false)
						{
							cnt2++;
							ok=true;
						}
					}
				}
			}
		}
		for(ll i=0;i<res.size();i++)
			{
				if(res[i]=='(' || res[i]==')')
				{
					if(f[i]==1) cout<<res[i];
				}
				else cout<<res[i];
			}
			cout<<endl;

	}
	return 0;
}

// thay the dau ngoac
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> st;     // stack nay luu vi tri cac dau sai
        int a[1005] = {0}; // a[i] = 1: Ngoac vi tri i dung/vi tri do khong la dau ngoac, a[i] = 0: Ngoac vi tri i sai
        for (int i = 0; i < s.size(); i++)
            a[i] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (!st.empty())
                {
                    // Danh dau dau mo 0 dau dong la 1
                    a[i] = 1;
                    a[st.top()] = 0;
                    st.pop();
                }
                else
                {
                    a[i] = -1;
                }
            }
        }
        while (!st.empty())
        { // Trong stack toan vi tri ngoac sai
            int p = st.top();
            a[p] = -1;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                cout << a[i];
            }
            else
                cout << s[i];
        }
        cout << endl;
    }
}

// day ngoac vuong dai nhat
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1;
    string s;
    while(t--)
    {
        cin >> s;
        int cnt = 0, res = 0;
        stack<pair<char, int>> st;
        st.push({'*', 0});
        for(char &i : s)
        {
            if(st.size() && ((i == ')' && st.top().first == '(') || (i == ']' &&  st.top().first == '[')))
            {
                st.pop();
                if(st.size())
                    res = max(res, cnt - st.top().second);
            }
            else
            {
                cnt += i == '[';
                st.push({i, cnt});
            }
        }
        cout << res;
    }
    return 0;
}

// so thu tu cap ngoac
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    string s;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        int cnt = 1;
        stack<int> st;
        for(char &i : s)
        {
            if(i == '(')
            {
                st.push(cnt);
                cout << cnt << ' ';
                ++cnt;
            }
            else if(i == ')')
            {
                cout << st.top() << ' ';
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}

// cay nhi phan 

// cay nhi phan du
#include<bits/stdc++.h>
using namespace std;
int n, check;

struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node *newNode = new node;
	newNode -> data = i;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	return newNode;
}

void buildTree(node *root, int par, int child, char c){
	if (root != NULL){
		if (root -> data == par){
			if (c == 'L') 
				root -> left = makeNode(child);
			else root -> right = makeNode(child);
		}
		buildTree(root -> left, par, child, c);
		buildTree(root -> right, par, child, c);
	}
}

void is_Check(node *root){
	if(root != NULL){
		if((root -> left == NULL && root -> right != NULL) || (root -> left != NULL && root -> right == NULL)){
			check = 0;
			return;
		}
		is_Check(root -> left);
		is_Check(root -> right);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		check = 1;
		int par, child;
		char c;
		cin >> par >> child >> c;
		node *root = NULL;
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		is_Check(root);
		if (check == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}


// cay nhi phan hoan hao
#include<bits/stdc++.h>
using namespace std;
int n, check;

struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node *newNode = new node;
	newNode -> data = i;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	return newNode;
}

void buildTree(node *root, int par, int child, char c){
	if (root != NULL){
		if (root -> data == par){
			if (c == 'L') 
				root -> left = makeNode(child);
			else root -> right = makeNode(child);
		}
		buildTree(root -> left, par, child, c);
		buildTree(root -> right, par, child, c);
	}
}

int is_True(node *root){
	queue<pair<node*, int>> q;
	pair<node*, int> top;
	q.push({root, 0});
	int max = -1;
	while(!q.empty())
	{
		top = q.front();
		q.pop();
		
		if(top.first->left == NULL)
		{
			if(max == -1)
				max = top.second;
			else if(top.second != max)
				return 0;
		}
		else q.push({top.first->left, top.second+1});
		
		if(top.first->right == NULL)
		{
			if(max == -1)
				max = top.second;
			else if(top.second != max)
				return 0;
		}
		else q.push({top.first->right, top.second+1});	
	}
	
	return 1;
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		check = 1;
		int par, child;
		char c;
		cin >> par >> child >> c;
		node *root = NULL;
		root = makeNode(par);
		buildTree(root, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root, par, child, c);
		}
		
		if (is_True(root) == 1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

// cay nhi phan bang nhau
#include<bits/stdc++.h>
using namespace std;
int n, check;

struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node *newNode = new node;
	newNode -> data = i;
	newNode -> left = NULL;
	newNode -> right = NULL;
	
	return newNode;
}

void buildTree(node *root, int par, int child, char c){
	if (root != NULL){
		if (root -> data == par){
			if (c == 'L') 
				root -> left = makeNode(child);
			else root -> right = makeNode(child);
		}
		buildTree(root -> left, par, child, c);
		buildTree(root -> right, par, child, c);
	}
}

void is_Cmp(node *root1, node *root2){
	if (root1 == NULL || root2 == NULL || check == 0)
		return;
	if (root1 -> data != root2 -> data) {
		check = 0;
		return;
	}
	if ((root1 -> left != NULL && root2 -> left == NULL) || (root1 -> right == NULL && root2 -> right != NULL)){
		check = 0;
		return;
	}
	is_Cmp(root1 -> right, root2 -> right);
	is_Cmp(root1 -> left, root2 -> left);
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		check = 1;
		int par, child;
		char c;
		cin >> par >> child >> c;
		node *root1 = NULL;
		root1 = makeNode(par);
		buildTree(root1, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root1, par, child, c);
		}
		
		cin >> n;
		cin >> par >> child >> c;
		node *root2 = NULL;
		root2 = makeNode(par);
		buildTree(root2, par, child, c);
		n--;
		while(n--){
			cin >> par >> child >> c;
			buildTree(root2, par, child, c);
		}
		
		is_Cmp(root1, root2);
		if (check == 1) cout << 1 << endl;
		else cout << 0 << endl;
	}
}

// cay nhi phan tim kiem can bang

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);	
		cout << a[(n-1)/2] << endl;
	}
}

// bfs va dfs

// dfs
#include<bits/stdc++.h>
using namespace std;
vector<int> e[1009];
int vs[10009];
int m, n;
void dfs(int u){
	vs[u] = 1;
	cout << u << " ";
	for (auto v : e[u]){
		if (vs[v] == 0) {
			vs[v] = 1;
			dfs(v);
		}
	}
	
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> m >> n;
		int u; cin >> u;
		for (int i = 1; i <= m; i++) e[i].clear();
		memset(vs, 0, sizeof(vs));
		for (int i = 0; i < n; i++){
			int a, b; cin >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		dfs(u);
		cout << endl;
	}
}

// bfs
#include<bits/stdc++.h>
using namespace std;
vector<int> e[1009];
int vs[10009];
int m, n;
queue<int> qe;
void bfs(int u){
	qe.push(u);
	vs[u] = 1;
	while(!qe.empty()) {
		int v = qe.front();
		qe.pop();
		cout << v << " ";
		for (auto x : e[v]){
			if(vs[x] == 0){
				vs[x] = 1;
				qe.push(x);
			}
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> m >> n;
		int u; cin >> u;
		for (int i = 1; i <= m; i++) e[i].clear();
		memset(vs, 0, sizeof(vs));
		for (int i = 0; i < n; i++){
			int a, b; cin >> a >> b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		bfs(u);
		cout << endl;
	}
}

// liet ke canh cau
#include<bits/stdc++.h>
using namespace std;

int n, c, vs[5000];
vector<vector<int>> v;
queue<int> q;
vector<pair<int, int>> a;
int m1, m2;

void BFS(int u)
{
	q.push(u);
	vs[u] = 1;
	
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		
		for(int x : v[k])
		{
			if((k == m1 && x == m2) || (k == m2 && x == m1))
				continue;
			if(vs[x] == 0)
			{
				vs[x] = 1;
				q.push(x);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		
		v.clear();
		cin >> n >> c;
		
		v.resize(n+2);
		int p1, p2;
		a.clear();
		a.resize(c);
		for(int i = 0; i< c; i++)
		{
			cin >> p1 >> p2;
			a[i].first = p1;
			a[i].second = p2;
			
			v[p1].push_back(p2);
			v[p2].push_back(p1);
		}
		
		for(int i = 1; i<= n; i++)
			vs[i] = 0;
		
		int res = 0;
		
		for(int i = 1; i <= n; i++)
		{
			if(vs[i] == 0)
			{
				BFS(i);
				res++;
			}
		}
		
		int cnt ;
		
		for(auto x : a)
		{
			//reset
			for(int i = 1; i<= n; i++)
				vs[i] = 0;
			cnt = 0;
			
			m1 = x.first;
			m2 = x.second;
			
			for(int j = 1; j <= n; j++)
			{
				if(vs[j] == 0)
				{
					cnt++;
					BFS(j);
				}
			}
			
			if(cnt > res)
			{
				cout << m1 << " " << m2 << " ";
			}
		}
		cout << endl;
	}
}

// liet ke dinh tru
#include<bits/stdc++.h>
using namespace std;

int n, c, vs[5000];
vector<vector<int>> v;
queue<int> q;

void BFS(int u)
{
	q.push(u);
	vs[u] = 1;
	
	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		
		for(int x : v[k])
		{
			if(vs[x] == 0)
			{
				vs[x] = 1;
				q.push(x);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		cin >> n >> c;
		
		v.resize(n+2);
		int p1, p2;
		for(int i = 0; i< c; i++)
		{
			cin >> p1 >> p2;
			v[p1].push_back(p2);
			v[p2].push_back(p1);
		}
		
		for(int i = 1; i<= n; i++)
			vs[i] = 0;
		
		int res = 0;
		
		for(int i = 1; i<=n; i++)
		{
			if(vs[i] == 0)
			{
				BFS(i);
				res++;
			}
		}
		
		int cnt ;
		
		for(int i = 1; i<= n; i++)
		{
			//reset
			for(int i = 1; i<= n; i++)
				vs[i] = 0;
			cnt = 0;
			
			vs[i] = 1;
			
			for(int j = 1; j <= n; j++)
			{
				if(vs[j] == 0)
				{
					cnt++;
					BFS(j);
				}
			}
			if(cnt > res)
			{
				cout << i << " ";
			}
		}
		cout << endl;
	}
}

// dinh tru va canh cau
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
vector<int> adj[1000001];
int visited[1000001];
vector<pair<int, int>> edge;

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : adj[u])
	{
		if (!visited[x])
			DFS(x);
	}
}

void DFS2(int u, int x, int y)
{
	visited[u] = true;
	for (auto z : adj[u])
	{
		if (z == x && u == y || z == y && u == x)
			continue;
		if (!visited[z])
		{
			DFS2(z, x, y);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edge.push_back({x, y});
	}
	int tplt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			tplt++;
			DFS(i);
		}
	}
	memset(visited, 0, sizeof(visited));
	int tru = 0; // Dinh tru
	for (int i = 1; i <= n; i++)
	{
		visited[i] = 1;
		int dem = 0;
		for (int j = 1; j <= n; j++)
		{
			if (!visited[j])
			{
				dem++;
				DFS(j);
			}
		}
		memset(visited, false, sizeof(visited));
		if (dem > tplt)
			tru++;
	}
	int cau = 0; // Canh cau
	for (auto e : edge)
	{
		int x = e.first, y = e.second;
		int dem = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				dem++;
				DFS2(i, x, y);
			}
		}
		if (dem > tplt)
			cau++;
	}
	cout << tru << " " << cau;
	return 0;
}

// khac

// dem duong di ngan nhat
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll n, m;
vector<pair<ll, ll>>adj[1000005];
ll route[1000005];
ll d[1000005];
void dijkstra(ll i) {
	fill(d + 1, d + n + 1, 1e18);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll> >> pq;
	d[i] = 0;
	pq.push({d[i], i});
	route[i] = 1;
	while (!pq.empty()) {
		auto top = pq.top();
		pq.pop();
		ll u = top.second;
		ll du = top.first;
		if (du > d[u]) continue;
		for (auto &x : adj[u]) {
			ll v = x.first;
			ll w = x.second;
			if (d[v] == d[u] + w) {
				route[v] += route[u];
			}
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				route[v] = route[u];
				pq.push({d[v], v});
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll x, y, c;
		cin >> x >> y >> c;
		adj[x].push_back({y, c});
		adj[y].push_back({x, c});
	}
	dijkstra(1);
	cout << d[n] << " " << route[n] << endl;
	return 0;
}
// diem nghen giao thong
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int>adj[1005];
bool visited[1005];

void DFS(int u) {
	stack<int>st;
	st.push(u);
	visited[u] = true;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		for (auto &y : adj[x]) {
			if (!visited[y]) {
				visited[y] = true;
				st.push(x);
				st.push(y);
			}
		}
	}
}
int t, n, m, u, v;
int main()
{

	cin >> t;
	while (t--) {
		cin >> n >> m >> u >> v;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			visited[i] = true;
			DFS(u);
			if (!visited[v]) cnt++;
			memset(visited, 0, sizeof(visited));
		}
		cout << cnt << endl;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}
// di chuyen tren do thi co trong so
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m, q, D[1005][1005];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int u = 1; u <= n; u++) {
			for (int v = 1; v <= n; v++) {
				D[u][v] = min(D[u][v], max(D[u][k], D[k][v]));
			}
		}
	}
}

int main()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) D[i][j] = 0;
			else D[i][j] = D[j][i] = 1e9;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		D[x][y] = w;
	}
	floyd();
	while (q--) {
		int x, y;
		cin >> x >> y;
		if (D[x][y] == 1e9) cout << -1;
		else cout << D[x][y];
		cout << endl;
	}
	return 0;
}

// doan lien tiep
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (auto &x : a) {
			cin >> x;
		}
		stack<int>st;
		int b[n];
		for (int i = 0; i < n; i++) {
			while (!st.empty() && a[st.top()] <= a[i])
				st.pop();
			if (st.empty()) b[i] = i + 1;
			else b[i] = i - st.top();
			st.push(i);
		}
		for (int i = 0; i < n; i++)
			cout << b[i] << " ";
		cout << endl;
	}
	return 0;
}
// do thi lien thong 2
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, m;
vector<int>adj[1005];
int low[1005], disc[1005];
int cnt;
vector<pair<int, int>>res;
void Tarjan(int u, int p) {
	disc[u] = low[u] = ++cnt;
	for (auto &v : adj[u]) {
		if (v == p) continue;
		if (disc[v]) {
			low[u] = min(low[u], disc[v]);
		} else {
			Tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] == disc[v]) {
				res.push_back({min(u, v), max(u, v)});
			}
		}
	}
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		res.clear();
		memset(low, 0, sizeof(low));
		memset(disc, 0, sizeof(disc));
		cnt = 0;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		Tarjan(1, 0);
		sort(res.begin(), res.end());
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++) {
			cout << "(" << res[i].first << " " << res[i].second << ") ";
		}
		cout << endl;
	}
	return 0;
}
// so buoc di chuyen it nhat
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int t, n, m;

int A[1005][1005];
int dp[1005][1005];

void BFS(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	dp[i][j] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first, b = x.second;
		if (a == n && b == m) {
			break;
		}
		int a1, b1;
		if (a + 1 <= n)
		{
			a1 = a + abs(A[a][b] - A[a + 1][b]), b1 = b;
			if (dp[a1][b1] == 1e9 && a1 <= n)
			{
				dp[a1][b1] = dp[a][b] + 1;
				q.push({a1, b1});
			}
		}
		if (b + 1 <= m)
		{
			a1 = a; b1 = b + abs(A[a][b] - A[a][b + 1]);
			if (dp[a1][b1] == 1e9 && b1 <= m)
			{
				dp[a1][b1] = dp[a][b] + 1;
				q.push({a1, b1});
			}
		}
		if (a + 1 <= n && b + 1 <= m)
		{
			a1 = a + abs(A[a][b] - A[a + 1][b + 1]);
			b1 = b + abs(A[a][b] - A[a + 1][b + 1]);
			if (dp[a1][b1] == 1e9 && (a1 <= n) && (b1 <= m))
			{
				dp[a1][b1] = dp[a][b] + 1;
				q.push({a1, b1});
			}
		}
	}
	return;
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> A[i][j];
				dp[i][j] = 1e9;
			}
		}
		BFS(1, 1);
		if (dp[n][m] == 1e9) cout << -1;
		else cout << dp[n][m];
		cout << endl;
	}
	return 0;
}
// thanh phan lien thong 2
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n, m;
int visited[100005];
vector<int>adj[100005];

void DFS(int u) {
	stack<int>st;
	st.push(u);
	visited[u] = 1;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		for (auto &y : adj[x]) {
			if (!visited[y]) {
				visited[y] = 1;
				st.push(x);
				st.push(y);
				break;
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		int tplt = 0;
		visited[i] = 1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				tplt++;
				DFS(i);
			}
		}
		cout << tplt << endl;
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}

// vua va quan ma
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;

int mx[8] = { -1, -2, -2, -1, 1, 2, 2, 1};
int my[8] = { -2, -1, 1, 2, 2, 1, -1, -2};

int vx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int vy[8] = {1, 1, 1, -1, -1, -1, 0, 0};

int dp1[1005][1005];
int dp2[1005][1005];

int flag1[1005][1005];
int flag2[1005][1005];

char a[1005][1005];

int xm, ym, xv, yv;

int ans = 1e9;

void King(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	flag1[i][j] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first;
		int b = x.second;
		for (int k = 0; k < 8; k++) {
			int i1 = a + vx[k];
			int j1 = b + vy[k];
			if (i1 < 1 || i1 > n || j1 < 1 || j1 > n || flag1[i1][j1]) continue;
			dp1[i1][j1] = dp1[a][b] + 1;
			q.push({i1, j1});
			flag1[i1][j1] = 1;
		}
	}
	return;
}

void Knight(int i, int j) {
	queue<pair<int, int>>q;
	q.push({i, j});
	flag2[i][j] = 0;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		int a = x.first;
		int b = x.second;
		for (int k = 0; k < 8; k++) {
			int i1 = a + mx[k];
			int j1 = b + my[k];
			if (i1 < 1 || i1 > n || j1 < 1 || j1 > n || flag2[i1][j1]) continue;
			dp2[i1][j1] = dp2[a][b] + 1;
			q.push({i1, j1});
			flag2[i1][j1] = 1;
		}
	}
	return;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				flag1[i][j] = flag2[i][j] = 1;
			}
			else if (a[i][j] == 'M') {
				xm = i; ym = j;
			} else if (a[i][j] == 'T') {
				xv = i;
				yv = j;
			}
		}
	}
	King(xv, yv);
	Knight(xm, ym);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp1[i][j] == dp2[i][j] && dp1[i][j] != 0) {
				ans = min(ans, dp1[i][j]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}

// chia cat do thi
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int t, n, m;
vector<int> adj[1000001];
int visited[1000001];

void DFS(int u)
{
	visited[u] = 1;
	for (auto x : adj[u])
	{
		if (!visited[x])
			DFS(x);
	}
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int tplt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
			{
				tplt++;
				DFS(i);
			}
		}
		memset(visited, 0, sizeof(visited));
		int ans = 0;
		int pos = 0;
		int ok = 0;
		for (int i = 1; i <= n; i++)
		{
			visited[i] = 1;
			int dem = 0;
			for (int j = 1; j <= n; j++)
			{
				if (!visited[j])
				{
					dem++;
					DFS(j);
				}
			}
			if (dem > tplt) {
				ok = 1;
				if (ans < dem) {
					ans = dem;
					pos = i;
				}
			}
			memset(visited, false, sizeof(visited));
		}
		if (ok)
			cout << pos << endl;
		else cout << 0 << endl;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
	}
	return 0;
}

// so nguyen thuy
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll calc(ll x, ll y, string c) {
	if (c == "+") return x + y;
	else if (c == "-") return x - y;
	else if (c == "*") return x * y;
	else return x / y;
}
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string>v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		stack<ll>st;
		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] == "+" || v[i] == "-" || v[i] == "*" || v[i] == "/") {
				ll x = st.top(); st.pop();
				ll y = st.top(); st.pop();
				st.push(calc(x, y, v[i]));
			} else {
				st.push(stoll(v[i]));
			}
		}
		cout << st.top() << endl;
	}
	return 0;
}




