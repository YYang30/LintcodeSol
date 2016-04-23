#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Find minimum in rotated sorted array with duplicates*/

/* Note: 因为不知道起点和终点。所以不能直接使用二分法。*/

// 暴搜 遍历一遍所有的！
class Solution_foo{
public:
	int findMin(vector<int> &num){
		int min = num[0];
		for(int i = 1; i < num.size(); i++){
			if(num[i] < min){
				min = num[i];
			}
		}
		return min;
	}
};

// 二分: 左指针每次向右移动一位。 逐渐向右赶。 右指针向左赶。区别在与，当相等的时候，右指针左移。

class Solution{
public:
	int findMin(vector<int>  &num){
		int left = 0;
		int right = num.size() - 1;
		while(left < right){
			int mid = left + (right - left) / 2;
			if(num[mid] > num[right]){
				left = mid + 1;
			}else if(num[mid] < num[right]){
				right = mid;
			}else{
				right--;
			}
		}
		return num[left];
	}
};