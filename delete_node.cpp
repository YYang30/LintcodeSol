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
	ListNode *removeElements(ListNode *head, int val){
		
		ListNode dummy;
		dummy.next = head;
		head = &dummy;

		while(head->next !=NULL){
			if(head->next->val == val){
				head->next = head->next->next;
			}else{
				head = head->next;
			}
		}
		return dummy.next;
	}
};

void print(ListNode *head){
	for(ListNode *node = head; node != NULL; node = node->next){
		cout<<node->val;
		cout<<"->";
	}
	cout<<"NULL"<<endl;
}


int main(){
	ListNode *node1 = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *head = node1;

	node1->next = node2;
	node2->next = node3;

	print(head);

	return 0;
}