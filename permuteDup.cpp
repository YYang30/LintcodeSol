#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/* Permutation with dup*/

/* 
* Input: [1,2,2]
* Output: [
*			[1,2,2],
*			[2,1,2],
*			[2,2,1]
*		  ]
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
	test.push_back(2);

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
