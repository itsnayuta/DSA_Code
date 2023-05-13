#include <bits/stdc++.h>
using namespace std;
int ans;
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

void buildTree(node* &root, int val){
	if (root == NULL){
		root = makeNode(val);
	}
	else {
		if(root -> data > val) buildTree(root -> left, val);
		else buildTree(root -> right, val);
	}
}

void order(node *root, int cnt){
	if (root -> right == NULL && root -> left == NULL){
		ans = max(ans, cnt);
		return;
	}
	else {
		if (root -> right != NULL) order(root -> right, cnt + 1);
		if (root -> left != NULL) order(root -> left, cnt + 1);
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		ans = 0;
		int n; cin >> n;
		int val;
		node *root = NULL;
		while(n--){
			cin >> val;
			buildTree(root, val);
		}
		order(root, 0);
		cout << ans;
		cout << endl;
	}
}
