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


class SolutionOne{
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:

        vector<vector<int> > BFS(TreeNode *root){
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

    vector<vector<int> > levelOrderBottom(TreeNode *root){
        vector<vector<int> > temp;
        temp = BFS(root);
        vector<vector<int> > result(temp.rbegin(), temp.rend());

        // vector<vector<int> > result;

        // temp = BFS(root);

        // while(!temp.empty()){
        //     result.push_back(temp.back());
        //     temp.pop_back();
        // }
        return result;
    }
};

int main(){
    return 0;
}
