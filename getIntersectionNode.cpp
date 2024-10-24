#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int numA = 1, numB = 1;
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    while (nodeA->next != nullptr) {
        nodeA = nodeA->next;
        numA++;
    }
    while (nodeB->next != nullptr) {
        nodeB = nodeB->next;
        numB++;
    }
    if (nodeA != nodeB) {
        return nullptr;
    }
    nodeA = headA, nodeB = headB;
    if (numA > numB) {
        int advancedA = numA - numB;
        while (advancedA--) {
            nodeA = nodeA->next;
        }
    } else {
        int advancedB = numB - numA;
        while (advancedB--) {
            nodeB = nodeB->next;
        }
    }
    while (nodeA != nodeB) {
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return nodeA;
}

int main() {
    vector<int> A = {4, 1, 8, 4, 5};
    vector<int> B = {2, 8, 4, 5};
    ListNode* headA = new ListNode(A[0]);
    ListNode* nodeA = headA;
    for (int i = 1; i < A.size(); i++) {
        headA->next = new ListNode(A[i]);
        headA = headA->next;
    }
    ListNode* headB = new ListNode(B[0]);
    ListNode* nodeB = headB;
    for (int i = 1; i < B.size(); i++) {
        headB->next = new ListNode(B[i]);
        headB = headB->next;
    }
    ListNode* ans =  getIntersectionNode(nodeA, nodeB);
    if (ans)
        cout << ans->val << endl;
}