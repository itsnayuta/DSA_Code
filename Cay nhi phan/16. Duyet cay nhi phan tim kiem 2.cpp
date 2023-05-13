#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
struct node {
	int data;
	node *left = NULL;
	node *right = NULL;
};

node *makeNode(int i){
	node * newNode = new node;
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
		if (root -> data > val) buildTree(root -> left, val);
		else buildTree(root -> right, val);
	}
}

void order(node* root){
	if (root != NULL){
		ans.push_back(root -> data);
		if (root -> right != NULL) order(root -> right);
		if (root -> left != NULL) order(root -> left);
		
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		ans.clear();
		int n; cin >> n;
		node *root = NULL;
		int val;
		while(n--){
			cin >> val;
			buildTree(root, val);
		}
		order(root);
		for (int i = ans.size() - 1; i >= 0; i--){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}
