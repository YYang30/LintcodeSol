#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* First bad version 
*/

class Solution{
public:
	int findFirstBadVersion(int n){
		int start = 1, end = n;
		while(start + 1 < end){
			int mid = start + ((end - start) >> 1);
			if(SVNRepo::isBadVersion(mid)){
				end = mid;
			}else{
				start = mid;
			}
		}
		if(SVNRepo::isBadVersion(start)) return start;
		return end;
	}
};

int main(){
	// do sth interesting!
	return 0;
}