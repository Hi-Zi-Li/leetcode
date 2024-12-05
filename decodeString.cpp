#include <string>
#include <stack>
#include <iostream>
using namespace std;

// string decodeString(string s) {
//     stack<string> stk;
//     stack<int> nums;
//     int n = s.size();
//     int i = 0;
//     for (i = 0; i < n; i++) {
//         if (s[i] == '[') {
//             continue;
//         } else if (s[i] == ']') {
//             int num = nums.top();
//             nums.pop();
//             string tmp = stk.top();
//             stk.pop();                
//             string result = "";
//             for (int j = 0; j < num; j++)
//                 result += tmp;
//             int j = i+1;
//             for (j = i+1; j < n; j++) {
//                 if (s[j] < 'a' || s[j] > 'z')
//                     break;
//                 result += s[j];
//             }
//             stk.push(result);
//             i = j-1;
//         } else if (s[i] >= '0' && s[i] <= '9') {
//             int j = i;
//             for (j = i; j < n; j++) {
//                 if (s[j] < '0' || s[j] > '9')
//                     break;
//             }
//             int num = stoi(s.substr(i, j-i));
//             nums.push(num);
//             i = j-1;
//         } else {
//             int j = i;
//             for (j = i; j < n; j++) {
//                 if (s[j] < 'a' || s[j] > 'z')
//                     break;
//             }
//             string tmp = s.substr(i, j-i);
//             stk.push(tmp);
//             i = j-1;
//         }
//     }
//     string ans = "";
//     while (!stk.empty()) {
//         ans = stk.top() + ans;
//         stk.pop();
//     }
//     return ans;
// }

string decodeString(string s) {
    stack<string> stk;
    int n = s.size();
    int i = 0;
    for (i = 0; i < n; i++) {
        if (s[i] == '[') {
            stk.push("[");
        } else if (s[i] == ']') {
            string tmp = "";
            while (stk.top()[0] != '[') {
                tmp = stk.top() + tmp;
                stk.pop();
            }
            stk.pop();
            int num = stoi(stk.top());
            stk.pop();               
            string result = "";
            for (int j = 0; j < num; j++)
                result += tmp;
            stk.push(result);
        } else if (s[i] >= '0' && s[i] <= '9') {
            int j = i;
            for (j = i; j < n; j++) {
                if (s[j] < '0' || s[j] > '9')
                    break;
            }
            stk.push(s.substr(i, j-i));
            i = j-1;
        } else {
            int j = i;
            for (j = i; j < n; j++) {
                if (s[j] < 'a' || s[j] > 'z')
                    break;
            }
            string tmp = s.substr(i, j-i);
            stk.push(tmp);
            i = j-1;
        }
    }
    string ans = "";
    while (!stk.empty()) {
        ans = stk.top() + ans;
        stk.pop();
    }
    return ans;
}

int main() {
    string s = decodeString("3[aa]2[bb]c");
    cout << s << endl;
    return 0;
}