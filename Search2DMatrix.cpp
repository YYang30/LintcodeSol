#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*Search a 2D Matrix*/

class solution{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target){
		
		int n = matrix.size();
		int m = matrix[0].size();
		if (m == 0 ||  n == 0) return false;

		int start = 0, end = n * m - 1;
		while(start + 1 < end){
			int mid = start + (end - start)/2;
			int row = mid / m;
			int col = mid % m;

			if(matrix[row][col] < target){
				start = mid;
			}else{
				end = mid;
			}
		}

		if(matrix[start / m][start % m] == target){
			return true;
		} 

		if(matrix[end / m][end % m] == target){
			return true;
		}
		return false;
	}
};

int main(){
	vector<vector<int> > m;
	vector<int> la;
	la.push_back(5);
	m.push_back(la);
	solution sol;
	cout<<"The result is: "<< sol.searchMatrix(m,2)<<endl;
}

