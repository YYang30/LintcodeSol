//
//  main.cpp
//  Yang_Sol
//
//  Created by YangYang on 16/4/20.
//  Copyright © 2016年 YangYang. All rights reserved.
//

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

class Solution{
public:
    
    ListNode *findNode(ListNode *head, int val){
          
        while(head->next != NULL){
            if(head->next->val != val){
                head = head->next;
            }else{
                return head;
            }
        }
        return NULL;
    }
    
    void swapNeighbor(ListNode *m, ListNode *n){
        ListNode *node1 = m->next;
        ListNode *temp = m->next;
        ListNode *node2 = m->next->next;
        
        m->next = node2;
        node1->next = node2->next;
        node2->next = temp;
    }
    
    void swapRomote(ListNode *m, ListNode *n){
        ListNode *temp = m->next;
        ListNode *temp2 = n->next->next;
        
        m->next = n->next;
        n->next->next = temp->next;
        n->next = temp;
        temp->next = temp2;
    }
    
    ListNode *swapNodes(ListNode *head, int v1, int v2){
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        if(head->next == NULL || head->next->next == NULL) return dummy->next;
        
        ListNode *n1_prev = findNode(head, v1);
        ListNode *n2_prev = findNode(head, v2);
        
        // if v1 or v2 doesn't exist, do nothing.
        if(n1_prev == NULL || n2_prev == NULL) return dummy->next;
        
        if(n1_prev->next == n2_prev){
            swapNeighbor(n1_prev, n2_prev);
        }else{
            if(n2_prev->next == n1_prev){
                swapNeighbor(n2_prev, n1_prev);
            }else{
                swapRomote(n1_prev, n2_prev);
            }
        }       
        return dummy->next;
    }
};

int main(){
    
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *head = node1;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    
    ListNode *dummy = head;
    
    while(head != NULL){
        cout<< head->val<< "-->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
    
    
    Solution sol;
    ListNode *result = sol.swapNodes(dummy, 1, 2);
    
    while(result != NULL){
        cout<< result->val << "-->";
        result = result->next;
    }
    
    cout<<"NULL"<<endl;
    return 0;
}