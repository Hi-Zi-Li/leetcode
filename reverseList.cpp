#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    int n = 1;
    int cnt = 0;
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }
    while (cnt < n-1) {
        ListNode *tmp = head->next;
        head->next = tail->next;
        tail->next = head;
        head = tmp;
        cnt++;
    }    
    return tail;
}

ListNode* reverseList2(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *detectCycle(ListNode *head) {
    static const int MASK = 1048576;
    static const int MAX_VAL = 1e5;
    ListNode* pos = nullptr;
    ListNode* cur = head;
    while (cur != nullptr) {
        if (cur->val >= MAX_VAL) {
            pos = cur;
            break;
        }
        cur->val += MASK;
        cur = cur->next;
    }
    cur = pos;
    while (cur->val >= MAX_VAL) {
        cur->val -= MASK;
        cur = cur->next;
    }
    return pos;
}


int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode* headA = new ListNode(A[0]);
    ListNode* nodeA = headA;
    for (int i = 1; i < A.size(); i++) {
        headA->next = new ListNode(A[i]);
        headA = headA->next;
    }
    ListNode* node = reverseList(nodeA);
    while (node != nullptr) {
        cout << node->val << endl;
        node = node->next;
    }
    return 0;
}