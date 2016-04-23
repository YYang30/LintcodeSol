#include <iostream>
#include <vector>

class TreeNode {
public:
	int val;
    TreeNode *left, *right;
    TreeNode(int val) {
    	this->val = val;
    	this->left = this->right = nullptr;
    }
};
 
 /* is Complete Binary Tree */

class ResultType{
public:
	 int depth;
	 bool isFull, isComplete;
	 ResultType(int depth, bool isFull, bool isComplete){
	 	this->depth = depth;
	 	this->isFull = isFull;
	 	this->isComplete = isComplete;
	 } 
};

class Solution{
public:
    /**
     * @param root, the root of binary tree.
     * @return true if it is a complete binary tree, or false.
     */

    bool isComplete(TreeNode* root){
    	ResultType result = helper(root);
    	return result.isComplete;
    }

private:
	ResultType helper(TreeNode *root){

	 	if(root == nullptr){
			ResultType result(0, true, true);
	 		return result;
	 	}

	 	// divide 
	 	ResultType left = helper(root->left);
	 	ResultType right = helper(root->right);

	 	//conquer: 3种情况
	 	if(!left.isComplete){
	 		ResultType result(-1, false, false);
	 		return result;
	 	}

	 	// if depth is the same, left should be full and right should be complete
	 	if(left.depth == right.depth){
	 		if(!left.isFull || !right.isComplete){
	 			ResultType result(-1, false, false);
	 			return result;
	 		}else{
	 			ResultType result(left.depth + 1, right.isFull, true);
	 			return result;
	 		}
	 	}

	 	// if left->depth = right->depth + 1, left should be full and right should also be full
	 	if(left.depth == right.depth + 1){
	 		if(!left.isComplete || !right.isFull){
	 			ResultType result(-1, false, false);
	 			return result;
	 		}else{
	 			ResultType result(left.depth + 1, false, true);
	 			return result;
	 		}｀
	 	}
	 	ResultType result(-1, false, false);
	 	return result;
	}
};

int main(){
	//do sth 
	return 0;
}














