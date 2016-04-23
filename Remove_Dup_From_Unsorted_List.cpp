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
	ListNode *removeDuplicates(ListNode *head){
		if(head == NULL || head->next == NULL) return head;
		
		map<int, bool> mp;
		mp[head->val] = true; // unique

		ListNode *tail = head;
		ListNode *curr = head->next;

		while(curr != NULL){
			if(mp.find(curr->val) == mp.end()){
				mp[curr->val] = true;
				tail->next = curr;
				tail = tail->next;
			}
			curr = curr->next;
		}
		tail->next = NULL;
		return head;
	}
};

int main(){
	// do sth 
	return 0;
}