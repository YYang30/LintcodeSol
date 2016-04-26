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

// detect cycle in a linked list.

class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head){
    	if(head == NULL || head->next == NULL) return NULL;

    	ListNode *fast, slow;
    	
    	fast = head->next;
    	slow = head;

    	while(fast !=slow){
    		//说明无环儿
    		if(fast == NULL || fast->next == NULL) return NULL;
    		fast = fast->next->next;
    		slow = slow->next;
    	}

    	//再次相遇的点！
    	while(head != slow.next){
    		head = head->next;
    		slow = slow->next;
    	}
    	return head;  
    }
};


int main(){

	// do sth 
	return 0;	
}


