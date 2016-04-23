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
						  vector<int> &postorder, int post_start, int post_end){
		if(in_start > in_end) return NULL;

		// 后序遍历： 左－>右->根. 因此后序遍历的序列最后一个元素 就是构造树的树根。
		TreeNode *root = new TreeNode(postorder[post_end]);
		// 找到分界点 
		int position = findPosition(inorder, in_start, in_end, postorder[post_end]);
		// divide and conquer
		root->left = myBuildTree(inorder, in_start, position - 1,
							    postorder, post_start, post_start + position - in_start - 1);
		root->right = myBuildTree(inorder, position + 1, in_end,
								postorder, post_start + position - in_start, post_end - 1);
		return root;
	}

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder){
    	if(inorder.size() != postorder.size()) return NULL;
    	return myBuildTree(inorder, 0, inorder.size() - 1,
    					   postorder, 0, postorder.size() - 1);
    }
};


int main(){
	// do sth 
	return 0;
}