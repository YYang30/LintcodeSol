#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* K closest numbers in sorted array 
* Time complexity: O(logn + k)
*/

class Solution{
private:
	int firstIndex(vector<int> &A, int target){
		int start = 0;
		int end = A.size() - 1;
		while( start + 1 < end){
			int mid = start  + (end - start) / 2;
			if(A[mid] >= target){
				end = mid;
			}else{
				start = mid;
			}
		}
		if(A[start] >= target){ 
			return start;
		}
		if(A[end] >= target){
			return end;
		}
		return A.size();
	}

public:
	vector<int> KClosestNumbers(vector<int> &A, int target, int k){
		vector<int> result(k);
		if(A.size() == 0 || k > A.size()){
			return A;
		} 
		// first closest number to target
		int index = firstIndex(A,target);

		int start = index - 1;
		int end = index;

		for(int i = 0; i < k; i++){
			if(start < 0){ // 第一个
				result[i] = A[end++]; 
			}else if(end >= A.size()){ // 最后一个
				result[i] = A[start--];
			}else{
				if(target - A[start] <= A[end] - target){
					result[i] = A[start--]; // 向前找
				}else{
					result[i] = A[end++];
				}
			}
		}
		return result;
	}
};


int main(){
	return 0;
}

















