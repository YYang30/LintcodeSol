#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Find minimum in rotated sorted array*/

/* Note: 因为不知道起点和终点。所以不能直接使用二分法。
逐渐移动左指针，直到第一个小于mid的点。
*/

class Solution{
public:
     /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
     int findMin(vector<int> &num){
          int left = 0;
          int right = num.size() - 1;
          while(num[left] > num[right]){
               int mid = (left + right) / 2;
               if(num[mid] >= num[left]){
                    left = mid + 1;
               }else{
                    right = mid;
               }
          }
          return num[left];
     }
};

int main(){
     //do sth
     return 0;
}