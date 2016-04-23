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

class Solution {
public:
   /*
    思路：删除链表中倒数第n个结点，尽量只扫描一遍。
    使用两个指针扫描，当第一个指针扫描到第N个结点后，
    第二个指针从表头与第一个指针同时向后移动，
    当第一个指针指向空节点时，另一个指针就指向倒数第n个结点了
    */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
       	ListNode *temp = dummy;

       	for(int i = 0; i < n; i++){
       		head = head->next;
       	}

       	while(head != NULL){
       		head = head->next;
       		temp = temp->next;
       	}
       	temp->next = temp->next->next;
       	return dummy->next;
 	  }
};

int main(){
	// do sth 
	return 0;
}