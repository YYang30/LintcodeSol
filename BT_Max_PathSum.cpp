#include <climits>
#include <iostream>
#include <cmath>



class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
        this->left = this->right = NULL;
    }
};
 

/*
* Binary Tree Max Path Sum

思路：

计算树的最长path有2种情况：

1. 通过根的path.

  (1)如果左子树从左树根到任何一个Node的path大于零，可以链到root上

  (2)如果右子树从右树根到任何一个Node的path大于零，可以链到root上

2. 不通过根的path. 这个可以取左子树及右子树的path的最大值。

所以创建一个inner class:

记录2个值：

1. 本树的最大path。

2. 本树从根节点出发到任何一个节点的最大path.

注意，当root == null,以上2个值都要置为Integer_MIN_VALUE; 因为没有节点可取的时候，是不存在solution的。以免干扰递归的计算
*/

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
     class ReturnType{
     public:
     	int maxSingle;
     	int max;
     	ReturnType(int maxSingle, int max){
     		this->max = max;
     		this->maxSingle = maxSingle;
     	}
     };

    int maxPathSum(TreeNode *root){
    	return dfs(root).max;
    }

    //深搜 
    ReturnType dfs(TreeNode *root){
    	ReturnType ret(INT_MIN, INT_MIN);

    	if(root == NULL) return ret;

    	//divide
    	ReturnType left = dfs(root->left);
    	ReturnType right = dfs(root->right);

    	int crossRoot = root->val;

    	//conquer
    	//if any of the path of left and right is < 0, do not add it. 
    	crossRoot +=fmax(0, left.maxSingle);
    	crossRoot +=fmax(0, right.maxSingle);

    	int maxSingle = fmax(left.maxSingle, right.maxSingle);
    	maxSingle = fmax(maxSingle, 0);
    	maxSingle += root->val;

    	ret.maxSingle = maxSingle;
    	ret.max = fmax(right.max, left.max);
    	ret.max = fmax(ret.max, crossRoot);

    	return ret;
    }
};


int main(){
	// do sth 
	return 0;
}

