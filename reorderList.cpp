#include <iostream>
#include <vector>

class ListNode{
public:
	int val;
	ListNode *next;
	ListNode(int val){
		this->val = val;
		this->next = NULL;
	}
};

class Solution{
public:
	void reorderList(ListNode *head){
		if(head == NULL) return;

		vector<ListNode*> nodes;
		ListNode *curr = head;
		while(curr != NULL){
			nodes.push_back(curr);
			curr = curr->next;
		}

		int len = nodes.size();
		int start = 0;
		int end = len -1;

		while(start < end){
			node[start]->next = nodes[end];
			node[end--]->next = node[++start];
		}
		nodes[start]->next = NULL;
	}
};


int main(){
	//do sth 
	return 0;
}