#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
* last position of target 
*/

class Solution{
private:
	int count(vector<int> &L, int length){
		int sum = 0;
		for(int i = 0; i < L.size(); i++){
			sum += L[i] / length;
		}
		return sum;
	}

public:
	int woodCut(vector<int> &L, int k){
		
		// find the longest wood 
		int max = 0;
		for(int i = 0; i < L.size(); i++){
			max = std::max(max, L[i]);
		}
		cout<<"Max is: "<<max<<endl;

		// find the longest wood !
		int start = 1, end = max;
		int mid = (end - start) >> 1; 
		while( start + 1 < end){
			mid = start + (end - start) / 2;
			// 还是不够长！
			if(count(L, mid) >= k){
				start = mid;
			}else{

				end = mid;
			}
		}
		if(count(L, end) >= k){
			return end;
		}
		if(count(L, start) >= k){
			return start;
		}
		return 0;
	}
};


int main(){
	vector<int> L;
	L.push_back(232);
	L.push_back(124);
	L.push_back(456);
	int k = 7;
	Solution sol;

	cout<<"Result is: "<<endl;
	cout<<"	"<<sol.woodCut(L, k)<<endl;

	return 0;
}










