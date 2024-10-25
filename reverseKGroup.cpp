#include "ListNode.hpp"
#include <vector>
#include <iostream>
using namespace std;

bool checkK(ListNode* tmp, ListNode* &nextList, int k) {
    for (int i = 0; i < k; i++) {
        if (tmp == nullptr) {
            nextList = nullptr;
            return false;
        }
        tmp = tmp->next;
    }
    nextList = tmp;
    return true;
}

ListNode* reverseList(ListNode* head, int k) {
    ListNode* node1 = head;
    ListNode* node2 = head->next;
    for (int i = 0; i < k-1; i++) {
        ListNode* tmp = node2->next;
        node2->next = node1;
        node1 = node2;
        node2 = tmp;
    }
    return node1;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1)
        return head;
    ListNode* deadNode = new ListNode();
    deadNode->next = head;
    ListNode* preList = deadNode;
    ListNode* nextList = nullptr;
    for (ListNode* tmp = head; checkK(tmp, nextList, k) ; tmp = tmp->next) {
        ListNode* tmpHead = reverseList(tmp, k);
        tmp->next = nextList;
        preList->next = tmpHead;
        preList = tmp;
    }
    return deadNode->next;
}

int main() {
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9};
    ListNode* head = new ListNode(nums[0]);
    ListNode* tmp = head;
    for (int i = 1; i < nums.size(); i++) {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    ListNode* ans = reverseKGroup(head, 2);
    return 0;
}