#include <queue>
#include <iostream>

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
 
 
 /*
 * Binary Tree Level Order Traversal: 二叉树的层次遍历 其实就是 BFS

	四种解法：
		 1. BFS
		 2. DFS
		 3. BFS with two queues
		 4. BFS queue with dummy node 
 */

class SolutionOne{
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root){
        vector<vector<int> > result;
        if(root == NULL) return result;

        queue<TreeNode *> Q;
        vector<int> level; // elements of each level
        
        Q.push(root);
        while(!Q.empty()){
            int size = Q.size();
            for(int i = 0; i < size; i++){
                TreeNode *head = Q.front(); 
                Q.pop();
                level.push_back(head->val);
                if(head->left != NULL) Q.push(head->left);
                if(head->right != NULL) Q.push(head->right);
            }
            result.push_back(level);
            level.clear();
        }
        return result;
    } 
};



class SolutionTwo{
public:
	vector<vector<int> > levelOrder(TreeNode *root){

	}
};

class SolutionThree{
public:
	vector<vector<int> > levelOrder(TreeNode *root){

    }
};

class SolutionFour{
public:
	vector<vector<int> > levelOrder(TreeNode *root){
	}
};


int main(){
	// do sth
	return 0;
}








