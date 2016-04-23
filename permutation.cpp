#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Permutation */

/* 
* The set [1,2,3,...n] contains a total of n! unique permutations.
* By listing and labeling all of the permutations in order, we get the following sequence
* (ie, for n = 3):
* "123", "132", "213", "231", "312", "321"
*
* Given n and k, return the kth permutation sequence.
* Note: Given n will be between 1 and 9 inclusive.
*/

class Solution{
public:
	vector<vector<int> > permute(vector<int> &num){
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		if(num.size() == 0) return result;
		do{
			result.push_back(num);
		}while(next_permutation(num.begin(), num.end()));
		return result; 
	}
};

int main(){
	vector<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);

	vector<vector<int> > result;
	Solution sol;
	result = sol.permute(test);
	
	cout<<"Answer is: "<<"\n";
	cout<<"["<<endl;
	for(vector<vector<int> >::size_type i = 0 ; i < result.size(); i++){
		cout<<"  [";
		for(vector<int>::size_type j = 0; j < result[i].size();j++){
			std::cout<< result[i][j];
			if(j < result[i].size() - 1){
				cout<<" ";
			}
		}
		cout<<"]"<<"\n";
		// if(i < out_put.size() - 1){
		// 	cout<<", ";
		// }
	}
	cout<<"]" <<"\n"<<endl;
}