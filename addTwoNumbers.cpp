#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* pre = nullptr;
    ListNode* tmp = head;
    while (tmp != nullptr) {
        ListNode* next = tmp->next;
        tmp->next = pre;
        pre = tmp;
        tmp = next;
    }
    return pre;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* pre1 = nullptr;
    ListNode* pre2 = nullptr;
    ListNode* tmp1 = l1;
    ListNode* tmp2 = l2;
    while (tmp1 != nullptr) {
        ListNode* tmp = tmp1->next;
        tmp1->next = pre1;
        pre1 = tmp1;
        tmp1 = tmp;
    }
    while (tmp2 != nullptr) {
        ListNode* tmp = tmp2->next;
        tmp2->next = pre2;
        pre2 = tmp2;
        tmp2 = tmp;
    }
    ListNode* ans = new ListNode();
    ListNode* ansHead = ans;
    ListNode* head1 = pre1, *head2 = pre2;
    int jin = 0;
    while (head1 != nullptr && head2 != nullptr) {
        ListNode* newNode = new ListNode((head1->val + head2->val + jin)%10);
        if (head1->val+head2->val+jin >= 10)
            jin = 1;
        else
            jin = 0;
        ans->next = newNode;
        ans = ans->next;
        head1 = head1->next;
        head2 = head2->next;
    }
    if (head1 != nullptr && head2 == nullptr) {
        head2 = head1;
        head1 = nullptr;
    }
    while (head2 != nullptr) {
        ListNode* newNode = new ListNode((head2->val + jin)%10);
        if (head2->val + jin >= 10)
            jin = 1;
        else
            jin = 0;
        head2 = head2->next;
        ans->next = newNode;
        ans = ans->next;
    }
    if (jin == 1) {
        ListNode* newNode = new ListNode(1);
        ans->next = newNode;
    }

    return reverseList(ansHead->next);
}



int main() {
    vector<int> nums1 = {2, 4, 9};
    vector<int> nums2 = {5, 6, 4, 9};
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* tmp1 = l1;
    ListNode* tmp2 = l2;
    for (int i = 0; i < nums1.size(); i++) {
        ListNode* newNode = new ListNode(nums1[i]);
        tmp1->next = newNode;
        tmp1 = tmp1->next;
    }
    for (int i = 0; i < nums2.size(); i++) {
        ListNode* newNode = new ListNode(nums2[i]);
        tmp2->next = newNode;
        tmp2 = tmp2->next;
    }
    ListNode* ans = addTwoNumbers(l1->next, l2->next);
    for (ListNode* tmp = ans; tmp != nullptr; tmp = tmp->next)
        cout << tmp->val << " ";
    cout << endl;
    return 0;
}