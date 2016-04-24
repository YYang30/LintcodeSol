#include <queue>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
* Zigzag level order traversal: from left to right, 
* then right to left for the next level, and alternate between.

*/

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root){
        vector<vector<int> > result;
        if(root == NULL) return result;

        queue<TreeNode *> Q;
        vector<int>  level; // elements of each level
        //BFS走起
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
        //开始倒垃圾
        vector<vector<int> > realRes;
        vector<int> collector;
        vector<int> temp;
        int counter = 1;

        while(!result.empty()){
            collector = result.front();
            result.pop_back();
           if(counter % 2 == 1){
            //反序输出： 右->左        
                while(!collector.empty()){
                    temp.push_back(collector.back());
                    collector.pop_back();
                    temp.clear();
                }
                realRes.push_back(temp);
           }else{
            //正常输出： 左－>右
                realRes.push_back(collector);
           }
           collector.clear();
           counter++;
        }// end of while
        return realRes;
    }
};


int main(){
	// do sth 
	return 0;
}

