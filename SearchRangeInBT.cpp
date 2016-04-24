#include <queue>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
	int val;
    TreeNode *left, *right;
    TreeNode(int val) {
    	this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution{
public:
	vector<int> answer;

	void dfs(TreeNode* node, int k1, int k2){
		// 向左找
		if(node->left && node->val >= k1)
			dfs(node->left, k1, k2);
		// 在范围内！
		if(node->val >= k1 && node->val <= k2)
			answer.push_back(node->val);
		// 向右找
		if(node->right && node->val <= k2)
			dfs(node->right, k1, k2);
	}

	vector<int> searchRange(TreeNode* root, int k1, int k2){
		if(root == NULL) return answer;

		dfs(root, k1, k2);
		return answer;
	}
};

int main(){
	// do sth 
	return 0;
}