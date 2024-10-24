#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

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
    if (pos == nullptr) return nullptr;
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
    headA->next = nodeA->next->next->next->next;
    ListNode* node = detectCycle(nodeA);
    if (node)
    cout << node->val << endl;
    return 0;
}