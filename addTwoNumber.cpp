#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

/*Add Two Numbers*/
/* 进位进到下一个节点*/

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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
		ListNode *head = new ListNode(0);
		ListNode *ptr = head;

		int carry = 0; // 当前位的和！
		while(true){
			
			if(l1 != NULL){
				carry += l1->val;
				l1 = l1->next;
			}
			
			if(l2 != NULL){
				carry += l2->val;
				l2 = l2->next;
			}

			ptr->val = carry%10; // 当前位 ！
			carry /= 10; // 进位 0 或 1

			if(l1 != NULL || l2 != NULL || carry != 0){
				ptr = (ptr->next = new ListNode(0));
			}else{
				break;
			}
		} 
		return head;
	}
};
 

int main(){
	// do sth 
	return 0;
}