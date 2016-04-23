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

class Solution {
private:
	int findPosition(vector<int> &order, int start, int end, int key){
		for(int i = start; i <= end; i++){
			if(order[i] == key){
				return i;
			}
		}
		return -1;
	}

	TreeNode *myBuildTree(vector<int> &inorder, int in_start, int in_end,
						  vector<int> &preorder, int pre_start, int pre_end){
		if(in_start > in_end) return NULL;

		// 前序遍历： 根->左－>右. 因此前序遍历的序列第一个元素 就是 构造树的树根。
		TreeNode *root = new TreeNode(preorder[pre_start]);
		//找到分界点 
		int position = findPosition(inorder, in_start, in_end, preorder[pre_start]);
		// divide and conquer
		root->left = myBuildTree(inorder, in_start, position - 1,
							    preorder, pre_start + 1, pre_start + position - in_start);
		root->right = myBuildTree(inorder, position + 1, in_end,
								preorder, position - in_end + pre_end + 1, pre_end);
		return root;
	}

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    	if(inorder.size() != preorder.size()) return NULL;
    	return myBuildTree(inorder, 0, inorder.size() - 1,
    					   preorder, 0, preorder.size() - 1);
    }
};


int main(){
	// do sth 
	return 0;
}