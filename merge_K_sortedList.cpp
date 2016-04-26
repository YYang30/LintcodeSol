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

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists){
    	if(lists.size() == 0) return NULL;
    	return mergeHelper(lists, 0, lists.size() - 1);
    }

private:
	ListNode *mergeHelper(vector<ListNode *> &lists, int start, int end){
		if(start == end) return lists.at(start);
		
		//连续二分
		unsigned mid = start + (end - start) / 2;
		ListNode *left = mergeHelper(lists, start, mid);
		ListNode *right = mergeHelper(lists, mid + 1, end);
		return mergeTwoLists(left, right);
	}

	ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
		ListNode *dummy = new ListNode(0);
		ListNode *tail = dummy;

		while(list1 != NULL && list2 != NULL){
			if(list1->val < list2->val){
				tail->next = list1;
				tail = list1;
				list1 = list1->next;
			}else{
				tail->next = list2;
				tail = list2;
				list2 = list2->next;
			}
		}
		if(list1 != NULL){
			tail->next = list1;
		}else{
			tail->next = list2;
		}
		return dummy->next;
	}
};


int main(){

	// do sth 
	return 0;
}