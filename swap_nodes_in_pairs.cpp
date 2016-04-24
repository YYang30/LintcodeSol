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

class Solution{
public:
	ListNode *swapPairs(ListNode *head){
		
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		head = dummy;

		while(head->next != NULL && head->next->next != NULL){
			ListNode *node1 = head->next;
			ListNode *node2 = head->next->next;
			//swap
			head->next = node2;
			node1->next = node2->next;
			node2->next = node1;

			//move forward to next pair
			head = node1;
		}
		return dummy->next;
	}
};

int main(){
	//do sth
	return 0;
}