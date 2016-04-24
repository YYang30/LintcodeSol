#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*
* Search for a Range
*/

class Solution{
public:
	vector<int> searchRange(vector<int> &A, int target){
		vector<int> result;
		int start, end, mid;

		result.push_back(-1);
		result.push_back(-1);
		if(A.size() == 0) return result;

		// search for lower bound:
		start = 0, end = A.size() - 1;
		while(start + 1 < end){
			mid = start + ((end - start) >> 1);
			if(A[mid] == target){
				end = mid;
			}else if(A[mid] < target){
				start = mid;
			}else{
				end = mid;
			}
		}
		if(A[start] == target){
			cout<<"debug1!"<<endl;
			result[0] = start;
			cout<<"start is"<<start<<endl;
		}else if(A[end] == target){
			result[0] = end;
		}else{
			result[0] = -1;
			result[1] = -1;
			return result;
		}

		//search for higher bound:
		start = 0;
		end = A.size() - 1;
		while(start + 1 < end){
			mid = start + ((end - start) >> 1);
			if(A[mid] == target){
				start = mid;
			}else if(A[mid] < target){
				start = mid;
			}else{
				end = mid;
			}
		}
		
		if(A[end] == target){
			result[1] = end;
			cout<<"debug!"<<endl;
			cout<<"end is " << end<<endl;
			cout<<"result[1] is "<< result[1]<<endl;
		}else if(A[start] == target){
			cout<<"debug3!"<<endl;
			result[1] = start;
		}else{
			cout<<"debug4!"<<endl;
			result[0] = -1;
			result[1] = -1;
			return result;
		}
		return result;
	}
};


int main(){
 	vector<int> A;
 	vector<int> rel;
 	A.push_back(1);
 	//A.push_back(0);
 	int target = 1;
 	Solution sol;
 	rel = sol.searchRange(A, target);

 	cout<<"Result is: "<<endl;
 	cout<<" [ "<<endl;
 	int a = rel[0];
 	int b = rel[1];	

 	cout<< "	" << a <<endl;
 	cout<< "	" << b <<endl;

 	cout<<" ] "<<endl;
}