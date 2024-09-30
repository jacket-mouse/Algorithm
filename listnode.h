//
// Created by l1491 on 2024/9/30.
//
#include <bits/stdc++.h>

struct ListNode{
    int val;
    ListNode* next;
};

// 链表删除，头节点单独讨论
ListNode* removeElements(ListNode* head, int val) {
    // 删除头节点
    while (head != NULL && head->val == val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    if (head == NULL)
        return NULL;
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* nhead = head;
    while (cur != NULL) {
        if (cur->val == val) {
            ListNode* temp = cur;
            pre->next = cur->next;
            cur = cur->next;
            delete temp;
        } else {
            pre = pre->next;
            cur = cur->next;
        }
    }
    return nhead;
}
// 链表删除，添加虚拟头节点
