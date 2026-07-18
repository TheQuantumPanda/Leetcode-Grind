/*Though easy but I feel like i have progressed a lot earlier 
I googleded and used GPT a lot whenever I stuck somewhere did same
with easy one too but completed this one in 7:48 mins and only error
beign a missing ; no logical mistake :D*/

/*Here is the code*/

class Solution {
public:
    int findGCD(vector<int>& nums) {
        long long max = nums[0];
        long long min = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > max) {
                max = nums[i];
            }
            else if (nums[i] < min) {
                min = nums[i];
            }
        }
        while (min != 0) {
            long long temp = min;
            min = max % min;
            max = temp;
        }
        int ans = max;

        return ans;
    }
};
