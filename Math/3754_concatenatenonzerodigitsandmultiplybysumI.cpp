/*An easy one i need to remove zeros then get a number without zeros and then there sum
Output is number without zero multiplied by sum of numbers*/
/*Here is the code*/
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        while (n > 0) {
            int place = 1;
            x = x + (n%10)*place;
            sum = sum + n%10;
            n = n/10;
            place = place*10; 
        }
        return x*sum;
    }
};
/*I am so fking dumb place = place*10 will also increment with 0 too sat there 5 min wondering
where tf my logic is wrong :( anyway there goes my attempt in not using if else*/
/*New code with if else */
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        long long sum = 0;
        int place = 1;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                x = x + digit * place;
                sum = sum + digit;
                place = place * 10;
            }
            n = n/10;
        }
        return x * sum;
    }
};
/*Could have saved some time if not for me beign dumb -_- probably like done in 7-8 mins instead of 20-25min of pondering what went wrong */
