#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* Find Peak Element
*/


class Solution {
public:
	int findPeak(vector<int> A){
		if(A.size() == 0) return -1;

		int start = 1;
		int end = A.size() - 2;
		while(start + 1 < end){
			int mid = (start + end) >> 1;
			if(A[mid] < A[mid - 1]){  // 峰值的下降延
				end = mid;
			}else if(A[mid] < A[mid + 1]){ // 翻过“山头”！
				start = mid; // 再回去！ 
			}else{
				end = mid;
			}
		}

		if(A[start] < A[end]){
			return end;
		}else{
			return start;
		}

		return -1;
	}
};

int main(){
	vector<int> test;
	Solution sol;
	test.push_back(1);
	test.push_back(2);
	test.push_back(1);
	test.push_back(3);
	test.push_back(4);
	test.push_back(5);
	test.push_back(6);
	test.push_back(7);
	cout<<"The solution is " << sol.findPeak(test)<<endl;
}

