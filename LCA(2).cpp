#include <vector>

using namespace std;

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */

/*
* Lowest Common Ancestor (2) : Divide and Conquer
*/

class Solution {
public:
    /**
     * @param root: The root of the tree
     * @param A, B: Two node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode *lowestCommonAncestorII(ParentTreeNode *root,
                                           ParentTreeNode *A,
                                           ParentTreeNode *B){
    	if(root == NULL) return NULL;
    	if(root == A || root == B) return root;

    	// divide 
    	ParentTreeNode *left = lowestCommonAncestorII(root->left, A, B);
    	ParentTreeNode *right = lowestCommonAncestorII(root->right, A, B);

    	//conquer:
    	if(left != NULL && right != NULL) return root;
    	if(left != NULL) return left;
    	if(right != NULL) return right;
    	return NULL;
    }
};


int main(){
	// do sth interesting !

	return 0;
}