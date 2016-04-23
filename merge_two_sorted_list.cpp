#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

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


class Solution{
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
		ListNode *dummy = new ListNode(0);
		ListNode *tmp = dummy;

		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				tmp->next = l1;
				l1 = l1->next
			}else{
				tmp->next = l2;
				l2 = l2->next;
			}
			tem = tem->next;
		}

		if(l1 != NULL) tmp ->next = l1;
		else tmp->next = l2;
		return dummy->next;
	}
};