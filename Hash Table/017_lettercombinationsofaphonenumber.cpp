/*Well the best way i can think of is a recursive approach*/
/*Here is the code*/
class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    void solve(string &digits, int index, string &current)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for(char ch : letters)
        {
            current.push_back(ch);
            solve(digits, index + 1, current);            // <-- Recursive Function Called
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
        string current = "";
        solve(digits, 0, current);
        return ans;
    }
};
/*Well 0ms runtime GPT suggested a tree sort of approach but suggested to not use hash table for better complexitity*/
/*Here is the code*/
/*
class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    void solve(string &digits, int index, string &current)
    {
        if(index == digits.size())
        {
            ans.push_back(current);
            return;
        }
        string letters = mp[digits[index] - '0'];
        for(char ch : letters)
        {
            current.push_back(ch);
            solve(digits, index + 1, current);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return {};
        string current;
        solve(digits, 0, current);
        return ans;
    }
};
*/
