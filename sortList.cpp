#include "ListNode.hpp"
#include <vector>
using namespace std;

// worst case: in ordered list
pair<ListNode*, ListNode*> quickSort(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return {head, head};
    ListNode* mid = head;
    ListNode* left = head, *right = head;
    bool isOrdered = true;
    while (right->next != nullptr) {
        ListNode* next = right->next;
        if (next->val < mid->val) {
            right->next = next->next;
            next->next = left;
            left = next;
            isOrdered = false;
        } else {
            if (right->val > right->next->val)
                isOrdered = false;
            right = right->next;
        }
    }
    if (isOrdered) {
        return {left, right};
    }
    mid = head->next;
    head->next = nullptr;
    auto [leftHead, leftTail] = quickSort(left);
    auto [rightHead, rightTail] = quickSort(mid);
    if (leftTail != nullptr)
        leftTail->next = rightHead;
    return {leftHead, rightTail};
}

ListNode* sortList(ListNode* head) {
    if (head == nullptr )
        return nullptr;
    return quickSort(head).first;
}

ListNode* mergeSort(ListNode* head, ListNode* tail) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* slow = head, *fast = head;
    while (fast != tail) {
        slow = slow->next;
        fast = fast->next;
        if (fast != tail)
            fast = fast->next;
    }
    ListNode* mid = slow;
    return mergeList(mergeSort(head, mid), mergeSort(mid, tail));
}

ListNode* mergeList(ListNode* list1, ListNode* list2) {
    ListNode* deadNode = new ListNode();
    ListNode* tmp1 = list1, *tmp2 = list2;
    ListNode* tmp = deadNode;
    while (tmp1 != nullptr && tmp2 != nullptr) {
        if (tmp1->val < tmp2->val) {
            tmp->next = tmp1;
            tmp1 = tmp1->next;
        } else {
            tmp->next = tmp2;
            tmp2 = tmp2->next;
        }
        tmp = tmp->next;
    }
    if (tmp1 == nullptr)
        tmp->next = tmp2;
    else
        tmp->next = tmp1;
    return deadNode->next;
}


int main() {
    vector<int> nums = {-1,5,3,4,0};
    ListNode* head = new ListNode(nums[0]);
    ListNode* tmp = head;
    for (int i = 1; i < nums.size(); i++) {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    auto sortedHead = sortList(head);
    printList(sortedHead);
    return 0;
}