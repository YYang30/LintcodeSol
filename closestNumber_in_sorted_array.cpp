#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* Closest Number in Sorted Array
* 先找到最接近的点。然后比较左右！
*/

class Solution{

private:
	int findNeighbor(vector<int> &A, int target){
		int start = 0;
		int end = A.size() - 1;
		while( start + 1 < end){
			int mid = start + (end - start) / 2;
			if(A[mid] < target){
				start = mid;
			}else{
				end = mid;
			}
		}

		if(A[start] >= target){
			return start;
		}
		if(A[end] >= target){
			return end;
		}
		return A.size(); // 最大的也比他小！
	}

public:
	int closestNumber(vector<int> &A, int target){
		if(A.size() == 0) return -1;
		
		int index = findNeighbor(A, target);
		
		if(index == 0){
			return 0;
		}
		if(index == A.size()){
			return A.size() - 1;
		}
		if(abs(target - A[index -1]) < abs(A[index] - target)){
			return index - 1;
		}else{
			return index;
		}
		return index;
	}
};

int main(){
	//doing something intertesing
	return 0;
}