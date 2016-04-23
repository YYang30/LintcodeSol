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

// delete the duplicates in sorted list(2)
// 有一个重复的 删所有

class Solution{
public:
  ListNode *deleteDuplicates(ListNode *head){
    if(head == NULL || head->next == NULL) return head;

    ListNode dummy(0);
    dummy.next = head;
    head = &dummy;

    while(head->next != NULL && head->next->next != NULL){
        if(head->nex   t->val == head->next->next->val){
            int val = head->next->val;
            while(head->next != NULL && head->next->val == val){
                head->next = head->next->next;
            }
        }else{
          head = head->next;
        }
    }
    return dummy.next;
  }
};



int main(){
    // do sth 
    return 0;
}

