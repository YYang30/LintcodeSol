#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*Search Insert Position*/


class solution{
public:
	int searchInsert(vector<int> &A, int target){
		//find first position >= target
		if(A.size() == 0){
			return 0;
		}

		int start = 0;
		int end = A.size() - 1;
		while(start + 1 < end){
			int mid = start + (end - start) / 2;
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
};

int main(){
	// do sth
	return 0;
}