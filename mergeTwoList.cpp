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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
		ListNode *dummy = new ListNode(0);
		ListNode *temp = dummy;

		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				temp->next = l1;
				l1 = l1->next;
			}else{
				temp->next = l2;
				l2 = l2->next;
			}
			temp = temp->next;
		}
		if(l1 != NULL) temp->next = l1;
		else temp->next = l2;
		return dummy->next;
	}
};


int main(){
	// do sth 
	return 0;
}