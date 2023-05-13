#include <bits/stdc++.h>
using namespace std;
int a[100003];
int cnt;
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

node *buildTree(int l, int r){
	if (l > r) return NULL;
	
	int m = (l + r) / 2;
	node *newNode = makeNode(a[m]);
	newNode -> left = buildTree(l, m-1);
	newNode -> right = buildTree(m+1, r);
	
	return newNode;
}

void order(node *root){
	if (root != NULL){
		if (root -> right == NULL && root -> left == NULL){
			cnt++;
			return;
		}
		else {
			if (root -> left != NULL) order(root -> left);
			if (root -> right != NULL) order(root -> right);
		}
	}
}
int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		cnt = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a + n);
		node * root = buildTree(0, n - 1);
		order(root);
		cout << cnt;
		cout << endl;
		
	}
}
