#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

static void printList(ListNode* head) {
    for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
        std::cout << tmp->val << " ";        
    }
    std::cout << std::endl;
}

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val): val(_val), next(nullptr), random(nullptr) {}
};

#endif