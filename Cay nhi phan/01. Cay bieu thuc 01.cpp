#include<bits/stdc++.h>
using namespace std;

struct node {
	char data;
	node *left;
	node *right;
};

node *makeNode(char s){
	node *newNode = new node;
	newNode -> data = s;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

void inorder(node *root){
	if (root != NULL){
		inorder(root -> left);
		cout << root -> data;
		inorder(root -> right);
	}
}

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		stack<node*> st;
		for (auto x : s){
			if (x == '+' || x == '-' || x == '*' || x == '/'){
				node *tmp = makeNode(x);
				
				tmp -> right = st.top();
				st.pop();
				tmp -> left = st.top();
				st.pop();
				st.push(tmp);
			}
			else  st.push(makeNode(x));
		}
		inorder(st.top());
		cout << endl;
	}
}
