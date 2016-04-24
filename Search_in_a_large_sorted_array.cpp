#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Search in a Big Sorted Array */
/* 使用倍增法在大数组中寻找！ 倍增＋二分。*/

class ArrayReader{
public:
	int get(int index){
		// do something
		// return the number on given index.
		// return -1 if index does not exist.
		return 0;
	}
};

/* note: 不知道 起点和终点。因此不能直接使用二分法。倍增end point。然后使用二分。*/
/* 先找终点，然后再二分！*/

class Solution{
public:
	 /**
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
     int searchBigSortedArray(ArrayReader *reader, int target){
     	int end = 0;
     	while(reader->get(end) != -1 && reader->get(end)< target){
     		end = end * 2 + 1;
     	}

     	int start = 0;
     	while(start + 1 < end){
     		int mid = start + (end - start) / 2;
     		//reader->get(mid) == -1 是为了防止 倍增的终点超过数组的最大长度。
     		if(reader->get(mid) == -1 || reader->get(mid) >= target){
     			end = mid;
     		}else{
     			start = mid;
     		}
     	}

     	if(reader->get(start) == target){
     		return start;
     	}
     	if(reader->get(end) == target){
     		return end;
     	}
     	return -1;	
     }
};

int main(){
	//do sth
	return 0;
}








