#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return true;
    ListNode* tmp = head;
    int n = 0;
    while (tmp != nullptr) {
        tmp = tmp->next;
        n++;
    }
    ListNode* pre = head;
    for (int i = 0; i < (n+1)/2; i++) {
        pre = pre->next;
    }
    ListNode* cur = pre->next;
    while (cur != nullptr) {
        ListNode* tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    ListNode* left = head;
    ListNode* right = pre;
    bool res = true;
    for (int i = 0; i < n/2; i++) {
        if (left->val != right->val) {
            res = false;
            break;
        }
        left = left->next;
        right = right->next;
    }
    ListNode* prev = nullptr;
    ListNode* rightHead = pre;
    for (int i = 0; i < n/2; i++) {
        ListNode* tmp = rightHead->next;
        rightHead->next = prev;
        prev = rightHead;
        rightHead = tmp;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 1};
    ListNode* head = new ListNode(nums[0]);
    ListNode* tmp = head;
    for (int i = 1; i < nums.size(); i++) {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    cout << isPalindrome(head) << endl;
    return 0;
}