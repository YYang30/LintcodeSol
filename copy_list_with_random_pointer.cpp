#include <iostream>

using namespace std;

struct RandomListNode{
	int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// copy list with random pointer
// 插入拷贝节点 --> 复制random 指针 --> 分解至两个独立列表 
// http://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html


class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 第一步： 
        // 复制前一个节点并插入到后边
    	RandomListNode *cur = head;
    	while(cur != NULL){
    		RandomListNode *temp = new RandomListNode(cur->label);
    		temp->next = cur->next;
    		cur->next = temp;
    		cur = temp->next;
    	}
    	//第二步：
    	// copy random pointer
    	cur = head;
    	while(cur != NULL){
    		RandomListNode *temp = cur->next;
    		if(cur->random != NULL)
    			temp->random = cur->random->next;
    		cur = temp->next;
    	}
    	//第三步：
    	// 分解为两个独立的链表
    	cur = head;
    	RandomListNode *dup = head == NULL? NULL: head->next;
    	while(cur != NULL){
    		RandomListNode *temp = cur->next;
    		cur->next = temp->next;
    		if(temp->next != NULL)
    			temp->next = temp->next->next;
    		cur = cur->next;
    	}
    	return dup;
    }
};





int main(){
	// do sth 
	return 0;
}