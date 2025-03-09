#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
    public:
        string decodeString(string s) {
            stack<int> stk;
            stack<char> stk_letter;
            int num = 0;
            for (char ch : s) {
                if (ch >= '0' && ch <= '9') {
                    if (num != 0) {
                        num *= 10;
                        num += int(ch - '0');
                    } else
                        num = int(ch - '0');
                    continue;
                }
                if (ch == '[') {
                    stk.push(num);
                    stk_letter.push(ch);
                    num = 0;
                }
                if (ch == ']') {
                    int tmp = stk.top();
                    stk.pop();
                    string str = "";
                    while (stk_letter.top() != '[') {
                        str += stk_letter.top();
                        stk_letter.pop();
                    }
                    stk_letter.pop();
                    string tmp_str = str;
                    for (int i = 1; i <= tmp; i++) {
                        str += tmp_str;
                    }
                    for (char ch : str) {
                        stk_letter.push(ch);
                    }
                }
                if (ch >= 'a' && ch <= 'z') {
                    stk_letter.push(ch);
                }
            }
            string ans = "";
            stack<char> stk_letter_tmp;
            while (!stk_letter.empty()) {
                stk_letter_tmp.push(stk_letter.top());
                stk_letter.pop();
            }
            while (!stk_letter_tmp.empty()) {
                ans += stk_letter_tmp.top();
                stk_letter_tmp.pop();
            }
            return ans;
        }
};

int main(){
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    return 0;
}