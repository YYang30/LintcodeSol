#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

 /*
 1. Binary Tree Pre_order Traversal
 	 Root-->Left-->Right (根-->左-->右)

 2. Binary Tree In_order Traversal
 	 Left-->Root-->Right (左-->根-->右)

 3. Binary Tree Post_order Traveral
	 Left-->Right-->Root (左-->右-->根)
*/ 

class Solution{
public:

	//Pre_order Traverse 
	vector<int> pre_order;
	void pre_traverse(TreeNode *root){
		if(root == NULL) return;
		pre_order.push_back(root->val);
		pre_traverse(root->left);
		pre_traverse(root->right);
	}

	vector<int> preorderTraversal(TreeNode *root){
		pre_order.clear();
		pre_traverse(root);
		return pre_order;
	}

	//In_order Traverse
	vector<int> in_order;
	void in_traverse(TreeNode *root){
		if(root == NULL) return;
		in_traverse(root->left);
		in_order.push_back(root->val);
		in_traverse(root->right);
	}

	vector<int> inorderTraversal(TreeNode *root){
		in_order.clear();
		in_traverse(root);
		return in_order;
	}

	//Post_order Traverse
	vector<int> post_order;
	void post_traverse(TreeNode *root){
		if(root == NULL) return;
		post_traverse(root->left);
		post_traverse(root->right);
		post_order.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode *root){
		post_order.clear();
		post_traverse(root);
		return post_order;
	}
};


int main(){
	//do sth interesting
	return 0;
}







