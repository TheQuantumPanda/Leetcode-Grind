/*Here is the my solution for this I went ahead and just made a reversed number and compared them*/

class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0) {
            return false;
        }

        int original = x;
        long long reversed = 0;

        while(x > 0) {

            int digit = x % 10;

            reversed = reversed * 10 + digit;

            x /= 10;
        }

        return original == reversed;
    }
};

/*GPT went with a two pointer sort of approach it compared the first and last of the number and moves inward*/

/*
class Solution {
public:
    bool isPalindrome(int x) {

        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        while(x > reversedHalf) {

            reversedHalf = reversedHalf * 10 + x % 10;

            x /= 10;
        }

        return (x == reversedHalf || x == reversedHalf / 10);
    }
};
*/
