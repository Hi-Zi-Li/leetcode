#include <vector>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* front = head;
    ListNode* back = head;
    for (int i = 0; i < n; i++)
        back = back->next;
    if (back == nullptr)
        return front->next;
    while (back->next != nullptr) {
        front = front->next;
        back = back->next;
    }
    front->next = front->next->next;
    return head;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6,7 , 8, 9, 0};
    ListNode* head = new ListNode(nums[0]);
    ListNode* tmp = head;
    for (int i = 1; i < nums.size(); i++) {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    ListNode* ans = removeNthFromEnd(head, 10);
    for (auto tmp = ans; tmp != nullptr; tmp = tmp->next) {
        cout << tmp->val << " ";
    }
    cout << endl;
}