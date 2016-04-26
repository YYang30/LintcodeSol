#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>


// Maximum Subarry: 两种解法： Greedy, DP. 

using namespace std;

// Greedy 
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums){
    	if(nums.size() == 0) return 0;

    	int max_ = INT_MIN, sum = 0;
    	for(int i = 0; i < nums.size(); i++){
    		sum += nums[i];
    		max = max(max, sum);
    		sum = max(sum,0);
    	}
    	return max;
    }
};

int main(){
	// do sth 
	return 0;
}