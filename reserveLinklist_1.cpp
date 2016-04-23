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
	ListNode *reverse(ListNode *head){
		ListNode *prev = NULL;
		
		while(head != NULL){
			ListNode *temp = head->next;
			head->next = prev;
			prev = head;
			head = temp;
		}
		return prev;
	}
};



int main(){
	//do sth 
	return 0;
}