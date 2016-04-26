/*
数组2.1.1
remove deuplciates in a sorted array
Requriment: with constant memory. 
*/

#include <iostream>
using namespace std;

class Solution{
public:
	int removeDuplicates(int A[], int n){
		if(n == 0) return 0;
		int index = 0;
		for(int i = 1; i < n; i++){
			if(A[index]!= A[i])
				A[++index] = A[i];
		}
		return index+1;
	}
};

int main(){
	
	int A[] = {1,1,3,4,4};
	int len, new_len;
	Solution sol;

	len = sizeof(A)/sizeof(*A);
	cout<< "Original length is: " << len <<"\n";
	new_len = sol.removeDuplicates(A, len);
	cout<< "After remove Duplicates: "<< new_len << "\n";
}





