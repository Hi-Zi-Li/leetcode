#include "ListNode.hpp"
#include <vector>
#include <queue>
using namespace std;

struct Compare {
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* dummyNode = new ListNode();
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    int k = lists.size();
    for (int i = 0; i < k; i++) {
        for (auto tmp = lists[i]; tmp != nullptr; tmp = tmp->next) {
            pq.push(tmp);
        }
    }
    ListNode* tmp = dummyNode;
    while (!pq.empty()) {
        tmp->next = pq.top();
        tmp = tmp->next;
        tmp->next = nullptr;
        pq.pop();
    }

    return dummyNode->next;
}

int main() {
    vector<vector<int>> vecs = {{-1, -1, -1}, {-2, -2, -1}};
    vector<ListNode*> lists;
    for (auto vec: vecs) {
        if (!vec.empty())
            lists.push_back(new ListNode(vec[0]));
        else {
            lists.push_back(nullptr);
        }
    }
    int k = vecs.size();
    for (int i = 0; i < k; i++) {
        int n = vecs[i].size();
        ListNode* tmp = lists[i];
        for (int j = 1; j < n; j++) {
            tmp->next = new ListNode(vecs[i][j]);
            tmp = tmp->next;
        }
    }
    ListNode* head = mergeKLists(lists);
    printList(head);
    return 0;
}