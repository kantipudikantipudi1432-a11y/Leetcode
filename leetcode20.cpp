#include <stack>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                // Check if stack is empty or top doesn't match
                if (st.empty() || st.top() != bracketMap[c]) {
                    return false;
                }
                st.pop();
            } else {
                // It's an opening bracket, push to stack
                st.push(c);
            }
        }

        return st.empty();
    }
};
