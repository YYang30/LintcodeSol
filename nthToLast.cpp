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
	ListNode *nthToLast(ListNode *head, int n){
		if(head == NULL || n < 1) return NULL;

		ListNode *p1 = head;
		ListNode *p2 = head;

		for(int i = 0; i < n - 1; i++){
			if(p2 == NULL) return NULL;
			p2 = p2->next;
		}

		while(p2->next != NULL){
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;
	
	}

};

int main(){
	// do sth 
	return 0;
}