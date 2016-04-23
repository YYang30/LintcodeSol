//
//  main.cpp
//  Yang_Sol
//
//  Created by YangYang on 16/4/20.
//  Copyright © 2016年 YangYang. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
    // ~ListNode(){}
};

// 两种解法： 1. 把链表顺序读入到一个vector 中。 然后再判断。
//			 2. 找中点。把后边一半reverse一下。然后对应比较。俩个指针一起向后移。

class Solution{
public:
	bool isPalindrome(ListNode *head){
		vector<int> result;
		while(head){
			result.push_back(head->val);
			head = head->next;
		}

		for(int i = 0, j = result.size() - 1; i < j; i++, j--){
			if(result[i] != result[j]) return false;
		}
		return true;
	}
};

int main(){

	// do sth 
	return 0;

}