#include <vector>

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
* Balanced Binary Tree
*/

class Solution{
public:
	bool isBalanced(TreeNode *root){
		return depth(root) != -1;
	}
private:
	int depth(TreeNode *root){
		if(root == NULL) return 0;
		int left = depth(root->left);
		int right = depth(root->right);
		if(left == -1 || right == -1|| abs(left - right) > 1){
			return -1;
		}
		return max(left,right) + 1;
	}
};