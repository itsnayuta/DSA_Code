#include<bits/stdc++.h>
using namespace std;
string a[150];
int n;

struct node {
	string data;
	node *left;
	node *right;
};

node *makeNode(string s){
	node *newNode = new node;
	newNode -> data = s;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

node *builtTree(node *root, int i){
	if (i < n){
		root = makeNode(a[i]);
		root -> left = builtTree(root -> left, 2 * i + 1);
		root -> right = builtTree(root -> right, 2 * i + 2);
	}
	return root;
}

long long calc(node *root){
	if (root -> data != "+" && root -> data != "-" && root -> data != "*" && root -> data != "/"){
		return stoll(root -> data);
	}
	
	if (root -> data == "+")
		return calc(root -> left) + calc(root -> right);
	if (root -> data == "-")
		return calc(root -> left) - calc(root -> right);
	if (root -> data == "*")
		return calc(root -> left) * calc(root -> right);
	if (root -> data == "/")
		return calc(root -> left) / calc(root -> right);
		
}
int main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		node *root = NULL;
		root = builtTree(root, 0);
		
		cout << calc(root) << endl;
		delete root;
	}
}
