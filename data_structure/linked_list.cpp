//
// Created by bw on 2022/8/31.
//
#include <iostream>

/**
 * 链表
 * @author hy
 */
struct ListNode {
    uint32_t val;
    ListNode *next;

    explicit ListNode(uint32_t value) {
        val = value;
        next = nullptr;
    }

    explicit ListNode(uint32_t value, ListNode *nextNode) {
        val = value;
        next = nextNode;
    }
};

int main() {
    ListNode *head;
    head = new ListNode(1, new ListNode(2, new ListNode(3)));

    while (head != nullptr) {
        std::cout << head->val << "\t";
        head = head->next;
    }
    return 0;
}
