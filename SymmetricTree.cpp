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

class Solution {
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a mirror of itself, or false.
     */
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return checkEqual(root->left, root->right);
    }
private:
	bool checkEqual(TreeNode *left, TreeNode *right){
		if(left == NULL && right == NULL) return true;
		if(left == NULL || right == NULL) return false;
		if(left->val != right->val) return false;

		return checkEqual(left->left, right->right) && checkEqual(left->right, right->left);
	}
};