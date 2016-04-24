#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* Search in Rotated Sorted Array:
* note: 两条线。分情况考虑。
*/

class Solution{
public:
	int search(vector<int> &A, int target){
		if(A.size() == 0) return -1;

		int start = 0;
		int end = A.size() - 1;
		int mid; 

		while(start + 1 < end){
			mid = start + (end - start) / 2;
			if(A[mid] == target){
				return mid;
			}
			// 分成两种情况： 
			if(A[start] < A[mid]){
				// case 1:
				if(A[start] <= target && target <= A[mid]){
					end = mid;
				}else{
					start = mid;
				}
			}else{
				//case 2:
				if (A[mid] <= target && target <= A[end]){
					start = mid;
				}else{
					end = mid;
				} // end of if 
			}// end of else
		} // end of while 
	if(A[start] == target){
		return start;
	}
	if(A[end] == target){
		return end;
	}
	return -1;

	}
};

int main(){
	//doing something interesting !
	return 0;
}




