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
* Lowest Common Ancestor: Divide and Conquer
*/

// 在root为根的二叉树中找A,B的LCA.
// 如果找到了就返回这个LCA. 如果只碰到A, 就返回A. 如果只碰到B, 就返回B. 如果都没有，就返回null.

class Solution{
public:
	TreeNode *lowestCommonAncestor(TreeNode *root,
								   TreeNode *A, 
								   TreeNode *B){
		if(root == NULL || root == A || root == B) return root;

		//divide:
		TreeNode *left = lowestCommonAncestor(root->left, A, B);
		TreeNode *right = lowestCommonAncestor(root->right, A, B);

		//Conquer:
		if(left != NULL && right != NULL) return root;
		if(left != NULL) return left;
		if(right != NULL)  return right;
		return NULL;
	}
};

int main(){
	//do sth interesting !
	return 0;
}
