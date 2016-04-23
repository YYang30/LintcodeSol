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
* Minimum Depth of Binary Tree
*/

class Solution{
public:
	int minDepth(TreeNode *root){
		if(root == NULL) return 0;
		int lMin = 0x7fffffff, rMin = 0x7fffffff;
        if(root->left == NULL && root->right == NULL) return 1;

		if(root->left) lMin = minDepth(root->left);
		if(root->right) rMin = minDepth(root->right);
		return min(lMin, rMin) + 1; 
	}
};


