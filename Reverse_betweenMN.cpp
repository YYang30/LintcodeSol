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
public:
	void reverse(ListNode *head){
		ListNode *prev = NULL;
		while(head != NULL){
			ListNode *temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
	}

	ListNode *findKthNode(ListNode *head, int k){
		for(int i = 0; i < k; i++){
			if(head == NULL) return head;
			head = head->next;
		}
		return head;
	}

	ListNode *reverseBetween(ListNode *head, int m, int n){
		ListNode *dummy = new ListNode(-1, head);
		ListNode *mth_prev = findKthNode(dummy, m - 1);
		ListNode *mth = mth_prev->next;
		ListNode *nth = findKthNode(dummy, n);
		ListNode *nth_next = nth->next;
		nth->next = NULL;

		reverse(mth);
		mth_prev->next = nth;
		mth->next = nth_next;
		return dummy->next;
	}
};

int main(){
	// do sth 
	return 0;
}