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
	ListNode *insertNode(ListNode *head, int val){
		ListNode *node = new ListNode(val);
		ListNode *dummy = new ListNode(0);
		dummy.next = head;
		head = dummy;

		// find the last elemnt <= val

		while(head->next != NULL && head->next->val <= val){
			head = head->next;
		}
		node.next = head->next;
		head->next = node;
		return dummy.next;
	}
};

int main(){
	// do sth
	return 0;
}