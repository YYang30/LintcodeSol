#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*Subarray Sum*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        unordered_map<int, int> hash;


        int sum = 0;
        hash[0] = -1;

        for(int i = 0; i < nums.size(); i++){
        	sum += nums[i];

        	if(hash.find(sum) != hash.end()){ // 找得到
        		vector<int> result;
                cout<<"sum = "<< sum <<"; i = "<< i << "; hash[sum] = "<< hash[sum] <<endl;
        		result.push_back(hash[sum] + 1);
        		result.push_back(i);
        		return result;
        	}
            cout<<"i!!!!!"<<endl;
        	hash[sum] = i;
        }
        vector<int> result;
        return result;
    }
};

int main(){

    Solution sol;
    vector<int> test;
    test.push_back(-3);
    test.push_back(1);
    test.push_back(2);
    test.push_back(-3);
    test.push_back(4);
    sol.subarraySum(test);
	return 0;
}