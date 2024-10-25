#include "ListNode.hpp"
#include <unordered_map>
using namespace std;

Node* copyRandomList_hash(Node* head) {
    unordered_map<Node*, Node*> node2Copy;
    Node* deadNode = new Node(0);
    Node* copyHead = deadNode;
    for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
        Node* newNode = new Node(tmp->val);
        copyHead->next = newNode;
        node2Copy[tmp] = newNode;
        copyHead = copyHead->next;
    }
    copyHead = deadNode->next;
    for (Node* src = head, *dst = copyHead; src != nullptr && dst != nullptr; src = src->next, dst = dst->next) {
        if (src->random == nullptr)
            dst->random = nullptr;
        else {
            dst->random = node2Copy[src->random];
        }
    }
    return copyHead;
}

Node* copyRandomList(Node* head) {
    if (head == nullptr)
        return nullptr;
    for (Node* tmp = head; tmp != nullptr; tmp = tmp->next->next) {
        Node* newNode = new Node(tmp->val);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
    for (Node* tmp = head; tmp != nullptr; tmp = tmp->next->next) {
        Node* newNode = tmp->next;
        newNode->random = tmp->random == nullptr? nullptr: tmp->random->next;
    }
    Node* copyListHead = head->next;
    for (Node* srcNode = head, *dstNode = head->next; srcNode != nullptr && dstNode != nullptr; srcNode = srcNode->next, dstNode = dstNode->next) {
        srcNode->next = dstNode->next;
        if (dstNode->next != nullptr) {
            dstNode->next = dstNode->next->next;
        }
    }
    return copyListHead;
}