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

/*
* 快慢指针法
*/

class Solution{
public:
	ListNode *middleNode(ListNode *head){

		if(head == NULL || head->next == NULL) return head;

		ListNode *slow = head, *fast = head->next;
		while(fast != NULL && fast->next != NULL){
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};

int main(){
	// do sth 
	return 0;
}