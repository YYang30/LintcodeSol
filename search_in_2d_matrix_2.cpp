#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
写出一个高效的算法来搜索 m × n矩阵中的值。

这个矩阵具有以下特性：
** 每行中的整数从左到右是排序的。
** 每行的第一个数大于上一行的最后一个整数。
*/

class Solution{
public:
	int searchMatrix(vector<vector<int> > &matrix,
					 int target){
		if(matrix.empty()) return 0;

		//from bottom left to top right
		int m = matrix.size(); //#rows
		int n = matrix[0].size(); //#cols

		int i = m - 1; 
		int j = 0;
		int count = 0;
		while(i >= 0 && j < n){
			if(matrix[i][j] == target){
				count++;
			}
			if(matrix[i][j] > target){
				i--;
			}else{
				j++;
			}
		}
		return count;
	}
};

int main(){
	vector<vector<int> > A;
	int target = 1;
	Solution sol;
	cout<<"Result is: " << sol.searchMatrix(A, target)<<endl;
	return 0;
}






