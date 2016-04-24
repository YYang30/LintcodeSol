#include <cstring>
#include <iostream>

using namespace std;

/*
* Return a index to the first occureence of target in source.
* or -1 if target is not part of source.
*/


class Solution{
public:
	int strStr(const char *source, const char *target){
		if(source == NULL or target == NULL) return -1;

		int src_size = strlen(source);
		int tar_size = strlen(target);
		int i, j;

		for(i = 0; i < src_size - tar_size + 1; i++){
			for(j = 0; j < tar_size; j++){
				if(source[i+j] != target[j]){
					break;
				}
			}
			if(j == tar_size){
				return i;
			}
		}
		return -1;
	}
};

int main(){

	int answer = 122;

	char src[] = "123456hh";
	char tar[] = "hh";

	Solution test;

	answer = test.strStr(src, tar);
	cout<<"Answer is:"<<answer<<endl;

	return 0;
}

