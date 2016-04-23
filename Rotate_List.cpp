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

// Given a list, rotate the list to the right by k places, where k is non-negative. 
// For example: Given 1->2->3->4->5->NULL and k = 2, return 4->5->1->2->3->NULL.

class Solution{
public:
	ListNode *rotateRight(ListNode *head, int k){
		if(head == NULL) return head;
		
		//get length
		int len = 0;
		ListNode *node = head;
		while(node != NULL){
			len++;
			node = node->next;
		}

		k = k % len; // 防止 k 比 len 的情况

		if(k == 0) return head; //不需要翻转

		ListNode *fast = head;
		ListNode *slow = head;

		for(int i = 0; i < k; i++){
			fast = fast->next;
		}

		while(fast->next != NULL){
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = head;
		head = slow->next;
		slow->next = NULL;

		return head;
	}

};

int main(){
	// do sth 
	return 0;
}







