#include <iostream>
#include <vector>

class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val){
		this->val = val;
		this->next = NULL;
	}
};

//Sort a linked list in O(n log n) time using constant space complexity.
// merge sort


class Solution{
private:

	ListNode *findMiddle(ListNode *head){
		ListNode *slow = head, *fast = head->next;
		while(fast != NULL && fast->next != NULL){
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}

	ListNode *merge(ListNode *l1, ListNode *l2){
		ListNode *dummy = new ListNode(0);
		ListNode *tail = dummy;

		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				tail->next = l1;
				l1 = l1->next;
			}else{
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		if(l1 != NULL){
			tail->next = l1;
		}else{
			tail->next = l2;
		}

		return dummy->next;
	}	

public:

	ListNode *sortList(ListNode *head){
		if(head == NULL || head->next == NULL){
			return head;
		}

		ListNode *mid = findMiddle(head);

		ListNode *right = sortList(mid->next);
		mid->next = NULL; //是为了左边的找到中点以后就停止
		ListNode *left = sortList(head);

		return merge(left,right);
	}
};

int main(){
	// do sth 
	return 0;
}
