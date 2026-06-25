/*This is a straight forward one i need to print the reverse of the given input
While beign mindfull if the 32 bit integer limit*/
/*I get the values by dividing by 10 continously and storing them in an array/vector
next i start multiplying them according to index position and addition
then i check if they are overflowing if yes then return 0*/
/*Here is the code*/
class Solution {
public:
    int reverse(int x) {
        vector<int> digits;
        long long ans = 0;
        bool negative = (x < 0);
        x = abs((long long)x);
        while(x > 0)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        for(int digit : digits)
        {
            ans = ans * 10 + digit;
        }
        if(negative)
            ans = -ans;
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
        return (int)ans;
    }
};

/*Fk GPT approch is almost same the only diffrence is that instead of saving it instead did the
multiplication simultaneously and did the overflow check first*/
/*Here is the code*/

/*
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0)
        {
            int digit = x % 10;
            if(ans > INT_MAX / 10 ||
               (ans == INT_MAX / 10 && digit > 7))
                return 0;
            if(ans < INT_MIN / 10 ||
               (ans == INT_MIN / 10 && digit < -8))
                return 0;
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};
*/
