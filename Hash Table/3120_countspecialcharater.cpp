
/*My approach is to use islower and isupper and use that to find the special character*/

/*Here is the code*/

class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> upper;
        for(char c : word) {
            if(islower(c)) {
                lower.insert(c);
            }
            if(isupper(c)) {
                upper.insert(c);
            }
        }
        int count = 0;
        for(char c : lower) {
            if(upper.count(toupper(c))) {
                count++;
            }
        }
        return count;
    }
};

/*GPT spat out three versions here are the solutions*/

/*
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, false);
        vector<bool> upper(26, false);
        for(char c : word) {
            if(islower(c)) {
                lower[c - 'a'] = true;
            }
            if(isupper(c)) {
                upper[c - 'A'] = true;
            }
        }
        int count = 0;
        for(int i = 0; i < 26; i++) {
            if(lower[i] && upper[i]) {
                count++;
            }
        }
        return count;
    }
};
*/

/*
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, bool> mp;
        for(char c : word) {
            mp[c] = true;
        }
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if(mp[c] && mp[toupper(c)]) {

                count++;
            }
        }
        return count;
    }
};
*/

/*
class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> st(word.begin(), word.end());
        int count = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            if(st.count(c) && st.count(toupper(c))) {
                count++;
            }
        }
        return count;
    }
};
*/
