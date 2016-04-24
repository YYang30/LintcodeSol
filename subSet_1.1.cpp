#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*Subset One: */

/* Given a set of distinct integers S, return all possible subsets.
*	Example:
*		S = [1,2,3]
*	Solution:
*		[
*			[],[1],[2],[3],[1,2],[1,3],[2,3],[1,2,3],	
*		]
*/

class Solution{
private:
	static void helper(vector<int> &S,
					   vector<int> &cur,
					   vector<vector<int> > &result,
					   int pos){
	
		result.push_back(cur);

		for(int i = pos; i < S.size(); i++){
			cur.push_back(S[i]);
			helper(S, cur, result, i + 1);
			cur.pop_back();
		}
	}

public:
	vector<vector<int> > subSetDup(vector<int> &S){
		vector<vector<int> > result;
		vector<int> cur;
		if(S.size() == 0) return result;
		int step = 0;
		sort(S.begin(), S.end());
		helper(S, cur, result, step);
		return result;
	}
};



int main(){
	vector<int> A; 
	// for(int i = 1; i < 4; i++){
	// 	A.push_back(i);
	// }
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	//A.push_back(15);
	//A.push_back(1);

	vector<vector<int> >  out_put;
	Solution test;
	out_put = test.subSetDup(A);

	cout<<"Answer is: "<<"\n";
	cout<<"["<<endl;
	for(vector<vector<int> >::size_type i = 0 ; i < out_put.size(); i++){
		cout<<"  [";
		for(vector<int>::size_type j = 0; j < out_put[i].size();j++){
			std::cout<< out_put[i][j];
			if(j < out_put[i].size() - 1){
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