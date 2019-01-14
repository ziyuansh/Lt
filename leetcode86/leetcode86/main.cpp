//
//  main.cpp
//  leetcode86
//
//  Created by ziyuan Shan on 1/13/19.
//  Copyright © 2019 ziyuan Shan. All rights reserved.
//

#include <iostream>
using namespace std;
struct ListNode {
         int val;
         ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    if(!head) return NULL;
    ListNode s = ListNode(0);
    ListNode b = ListNode(0);
    ListNode* cur = head;
    ListNode* sm = &s;
    ListNode* bi = &b;
    while(cur){
        if(cur->val < x){
            sm->next = cur;
            sm = sm->next;
        }
        else{
            bi->next = cur;
            bi = bi->next;
        }
        cur = cur->next;
    }
    sm->next = b.next;
    return s.next;
}
int main(int argc, const char * argv[]) {
    ListNode head = ListNode(1);
    ListNode l2 = ListNode(4);
    ListNode l3 = ListNode(3);
    ListNode l4 = ListNode(2);
    ListNode l5 = ListNode(5);
    ListNode l6 = ListNode(2);
    head.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    
    ListNode *h = partition(&head, 3);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
