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
* Validate BST
*/

class Solution{
public:
	int lastVal = INT_MIN;
	bool firstNode = true;
	bool isValidBST(TreeNode *root){
		if(root == NULL) return true;
		if(!isValidBST(root->left)) return false;
		if(!firstNode && lastVal >= root->val) return false;

		firstNode = false;
		lastVal = root->val;

		if(!isValidBST(root->right)) return false;
		return true;
	}
};

int main(){
	return 0;
}