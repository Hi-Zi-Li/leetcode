#include <string>
#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    int maxLen = 0;
    int n = s.size();
    stack<int> stk;
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            if (stk.empty()) {
                start = i;
            } else {
                stk.pop();
                if (stk.empty())
                    maxLen = max(maxLen, i-start);
                else
                    maxLen = max(maxLen, i-stk.top());
            }
        }
    }
    return maxLen;
}

int main() {
    cout << longestValidParentheses("(()()") << endl;
    cout << longestValidParentheses("(()") << endl; // 2
    cout << longestValidParentheses(")()())") << endl; // 4
    cout << longestValidParentheses("()(()") << endl; // 2
    cout << longestValidParentheses("(()())") << endl; // 6
    cout << longestValidParentheses("))))())()()(()") << endl; // 4
}