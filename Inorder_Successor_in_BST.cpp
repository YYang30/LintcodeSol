#include <climits>
#include <iostream>
#include <cmath>

struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
/*
* Inorder Successor in Binary Search Tree: 找下一个比input 大的node!
* In Binary Search Tree, Inorder Successor of an input node can also be defined as the node with the smallest key greater than the key of input node. 
* So, it is sometimes important to find next node in sorted order.
*/

class Solution{
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
		TreeNode *successor = NULL;
		while(root != NULL && root->val != p->val){
			if(root->val > p->val){
				successor = root;
				root = root->left;
			}else{
				root = root->right;
			}
		}
		if(root == NULL) return NULL;
		if(root->right == NULL) return successor;

		root = root->right;
		while(root->left != NULL){
			root = root->left;
		}
		return root;
	}
};


int main(){
	//do sth
	return 0;
}