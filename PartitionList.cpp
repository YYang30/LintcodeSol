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
	ListNode *partition(ListNode *head, int x){
		ListNode *leftDummy = new ListNode(0);
		ListNode *rightDummy = new ListNode(0);
		ListNode *leftTail = leftDummy;
		ListNode *rightTail = rightDummy;

		while(head != NULL){
			if(head->val < x){
				//leftTail = leftTail->next;
				leftTail->next = head;
				leftTail = head;
			}else{
				rightTail->next = head;
				rightTail = head;
			}
			head = head->next;
		}

		leftTail->next = rightDummy->next;
		rightTail->next = NULL;
		return leftDummy->next;
	}
};

int main(){
	//do sth 
	return 0;
}