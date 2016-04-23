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

//判断链表是否有环： 快慢指针法

class Solution{
public:
	bool hasCycle(ListNode *head){
		
		if(head == NULL) return false;

		ListNode *fast = head->next;
		ListNode *slow = head;

		while(fast !=NULL && fast->next !=NULL){
			if(slow == fast) return true;
			slow = slow->next;
			fast = fast->next->next;
		}
		return false;
	}
};



int main(){
	// do sth 
	return 0;
}