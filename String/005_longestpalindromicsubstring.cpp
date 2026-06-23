/*Here i approched with geting the center of string of string which yeilds two cases
Odd -> that is the center use to two pointer left and right of it and compare them when equal move forward
Even -> that location and location +1 will act as center but they will need to be compared first then movev left and right*/

/*Whoops failed at a test case where it is just two characters and they are not same I failed to properly comprehend the part longest palindrome
this mean just one character like "a" and i am returning nil when they are not equal*/
/*New fatal flaw it start from 0 index instead of centered index I use
So now every index is a posible center*/

/*Final Fixed Code*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;
        auto expand = [&](int left, int right) {
            while(left >= 0 &&
                  right < s.size() &&
                  s[left] == s[right])
            {
                int len = right - left + 1;
                if(len > maxLen)
                {
                    maxLen = len;
                    start = left;
                }
                left--;
                right++;
            }
        };
        for(int i = 0; i < s.size(); i++)
        {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};
/*Here is the GPT approach. It says it is the optimal solution but from what I see it is somewhat the approach I took like i can see the two pointers and every index is a center*/
