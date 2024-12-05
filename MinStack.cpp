#include <deque>
#include <queue>
using namespace std;

class MinStack {
public:
    deque<int> stk;
    deque<int> monoto;

    MinStack() {}

    void push(int val) {
        stk.emplace_back(val);
        auto it = lower_bound(monoto.begin(), monoto.end(), val);
        monoto.insert(it, val);
    }

    void pop() {
        int val = stk.back();
        stk.pop_back();
        auto it = lower_bound(monoto.begin(), monoto.end(), val);
        if (it != monoto.end() && *it == val) {
            monoto.erase(it);
        }
    }

    int top() {
        return stk.back();
    }    

    int getMin() {
        return monoto.front();
    }
};

int main() {
    MinStack minStk;
    minStk.push(-2);
    minStk.push(0);
    minStk.push(-3);
    int a = minStk.getMin();
    minStk.pop();
    int b = minStk.top();
    int c = minStk.getMin();
    return 0;
}

