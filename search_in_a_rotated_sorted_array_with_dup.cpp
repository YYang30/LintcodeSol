#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
* Search in a rotated sorted array with duplicated element!
*Note: 无论用不用二分，时间复杂度都是 O(n). 因此从实现的角度讲，顺序查找更简单。
*/

class Solution {
    /** 
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean 
     */
public:
    bool search(vector<int> &A, int target){
        for(int i = 0; i < A.size(); i++){
            if(A[i] == target){
                return true;
            }
        }
        return false;
    }
};