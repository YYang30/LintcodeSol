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
	ListNode *insertionSortList(ListNode *head){
		ListNode *dummy = new ListNode(0);

		while(head != NULL){
			ListNode *temp = dummy;
			ListNode *curr = head->next;

			while(temp->next != NULL && temp->next->val < head ->val){
				temp = temp->next;
			}

			head->next = temp->next;
			temp->next = head;
			head = curr;

		}
		return dummy->next;
	}
};

int main(){
	// do sth 
	return 0;
}