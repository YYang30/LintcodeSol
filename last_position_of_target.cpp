#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* last position of target 
*/

class Solution{
public:
	int lastPosition(vector<int> &A, int target){
		if(A.size() == 0) return -1;

		int start = 0, end = A.size() - 1;
		while(start + 1 < end){
			int mid = start + (end - start) / 2;
			if(A[mid] > target){
				end = mid;
			}else{
				start = mid;
			}
		}
		if(A[end] == target){
			return end;
		}
		if(A[start] == target){
			return start;
		}
		return -1;
	}
};

int main(){
	//doing sth interesting!
	return 0;
}
