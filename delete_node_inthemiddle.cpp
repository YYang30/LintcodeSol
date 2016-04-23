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

//删链表节点：非表头／尾

class Solution{
public:
	void deleteNode(ListNode *node){
		if(node == NULL || node->next == NULL) return;
		// 其实浪费了一个点！只是把这点的值改成了下一个点，然后把指针指到了下一个！
		ListNode *temp = node->next;
		node->val = temp->val;
		node->next = temp->next;
		return;
	}
};

int main(){
	// do sth 
	return 0;
}