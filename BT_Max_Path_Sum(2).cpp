#include <climits>
#include <iostream>
#include <cmath>

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
 * Binary Tree Maximum Path Sum(2): find teh maximum path sum from root. 
 */

class Solution {
public:
    /**
     * @param root the root of binary tree.
     * @return an integer
     */

    int maxPathSum2(TreeNode *root) {
    	return dfs(root);
    }

private:
	int dfs(TreeNode *root){
		int maxPathSum = INT_MIN;
		if(root == NULL) return maxPathSum;

		//devide 
		int left = dfs(root->left);
		int right = dfs(root->right);

		//conquer
		maxPathSum = fmax(fmax(left, right), 0);
		return maxPathSum + root->val;
	}
};






int main(){
	// do sth
	return 0;
}








