#include "ListNode.hpp"

ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* next = head->next;
    head->next = next->next;
    next->next = head;
    ListNode* pre = head;
    head = pre->next;
    for (ListNode* tmp = head; tmp != nullptr && tmp->next!= nullptr; tmp = tmp->next) {
        ListNode* tmp1 = tmp;
        ListNode* tmp2 = tmp->next;
        pre->next = tmp2;
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
        pre = tmp1;
    }
    return next;
}