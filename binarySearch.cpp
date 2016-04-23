#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Binary Search*/

/*
* Input: given target & sorted array[]
* Output: index of first occurrence.
*/

class solution{
public:
	int binarySearch(vector<int> &Array, int target){
		if(Array.size() == 0) return -1;

		int start = 0;
		int end = Array.size() - 1;
		int mid;

		while(start + 1 < end){
			mid = start + (end - start)/2;
			if(Array[mid] < target){
				//go right
				start = mid;
			}else{
				//go left;
				end = mid;
			}
		}

		if(Array[start] == target){
			return start;
		} 
		if(Array[end] == target){
			return end;
		}
		return -1;
	}
};

