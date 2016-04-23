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
* Binary Tree Path Sum 解法二更精简！
*/

// 解法一

class Solution{
public:
	vector<vector<int>> binaryTreePathSum(TreeNode *root, int target){
		vector<vector<int>> result;
		vector<int> path;
		dfs(root, path, result, 0, target);
		return result;
	}

private:
	void dfs(TreeNode *root,
			 vector<int> &path,
			 vector<vector<int>> &result,
			 int length,
			 int target){
		if(root == NULL){
			return;
		}
		path.push_back(root->val);
		length += root->val;
		if(root->left == NULL && root->right == NULL && length == target){
			result.push_back(path);
		}

		dfs(root->left, path, result, length, target);
		dfs(root->right, path, result, length, target);

		length -= root-> val;
		path.pop_back();
	}
};

// 解法二:

class Solution_2{
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum){
		vector<vector<int>> result;
		vector<int> cur; // 记录中间结果
		helper(root, sum, cur, result);
		return result;
	}
private:
	void helper(TreeNode *root, 
				 int length, 
				 vector<int> &cur,
				 vector<vector<int> > &result){
		if(root == nullptr) return;

		cur.push_back(root->val);

		//leaf node
		if(root->left == NULL && root->right == NULL){
			if(root->val == length){
				result.push_back(cur);
			}
		}
		helper(root->left, length - root->val, cur, result);
		helper(root->right, length - root->val, cur, result);

		cur.pop_back();
	}
};




int main(){
	//do something interesting
	return 0;
}














