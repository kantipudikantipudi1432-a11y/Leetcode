#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        // Mapping of digits to letters
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        
        vector<string> result;
        string current;
        backtrack(digits, mapping, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& digits, const vector<string>& mapping, int index, string& current, vector<string>& result) {
        // Base case: if current combination length matches digits length, we found a result
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters corresponding to the current digit
        string letters = mapping[digits[index] - '0'];
        for (char c : letters) {
            current.push_back(c);             // Add character
            backtrack(digits, mapping, index + 1, current, result); // Move to next digit
            current.pop_back();              // Remove character (backtrack)
        }
    }
};
