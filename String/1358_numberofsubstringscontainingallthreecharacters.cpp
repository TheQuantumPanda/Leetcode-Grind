/*Boom an easy one i just have to check if there are 'a', 'b', 'c'*/
/*My approach use 3 if condition to find the ans*/
/*Here is the solution*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j + 2 < s.size(); j++) {
                if (s[j] == 'a' || s[j] == 'b' || s[j] == 'c') {
                    if (s[j + 1] == 'a' || s[j + 1] == 'b' || s[j + 1] == 'c') {
                        if (s[j + 2] == 'a' || s[j + 2] == 'b' || s[j + 2] == 'c') {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
/*Wrong Method this will also count some thing like 'aaa' or 'aac' that is not acceptable*/
/*20mins later saw topics of the given solution it says sliding window the concept is same as computer networks sliding window
a buffer that stores values in this case buffer of 3 but not array type buffer I just the conformation that previous one is a or b or c*/
/*Here is the code*/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++)
        {
            bool hasA = false;
            bool hasB = false;
            bool hasC = false;
            for(int j = i; j < s.size(); j++)
            {
                if(s[j] == 'a') hasA = true;
                if(s[j] == 'b') hasB = true;
                if(s[j] == 'c') hasC = true;
                if(hasA && hasB && hasC)
                    count++;
            }
        }
        return count;
    }
};
/*Well it works somewhat got a timelimit exceed error*/
/*Tf is that input why does it have to be so absurldy huge the number of characters are close to 50k*/
/*Well GPT says sliding window is the intended optimal soltion her is the fixed GPT code*/
/*
class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0, 0, 0};
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += s.size() - right;
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};
*/
