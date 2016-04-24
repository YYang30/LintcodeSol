#include <iostream>
#include <cstring>
#include <vector>

/*
Note: 用两次二分，先找第一个出现的点。再找最后一个出现的点。做差。
*/
using namespace std;

class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int totalOccurrence(vector<int>& A, int target){
        int n = A.size();
        if(n == 0) return 0;
        if(A[0] > target || A[n-1] < target) return 0;

        int low = 0, high = n - 1;
        int start = 0; 
        while(low <= high){
            int mid = (low + high) >> 1; // 除2.
            if(A[mid] >= target){
                start = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        //判断是否存在
        if(A[start] != target) return 0;       

        //找结束的点 ！
        int end = n - 1;
        low = start, high = n-1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(A[mid] <= target){
                end = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return end - start + 1;
     }
 };


// A = [1,3,3,4,5] target = 3;



 int main(){
    vector<int>  A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);

    int target = 3;

    Solution sol;
    cout<<sol.totalOccurrence(A, target)<<endl;
 }
