/*Well the question seems easy but given my track record I shouldn't underestimate the question
I am going with a three pointer approch this will find every possible combination*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        if(find(ans.begin(), ans.end(), temp) == ans.end())
                            ans.push_back(temp);
                    }
                }
            }
        }
        return ans;
    }
};
/*Well got a Time limit exceeding error well did knew question was looking too easy for a medium*/
/*New method still will use three pointer sort of but will first sort the array the goal is have sum 0
so first pointer is still fixed but now there two pointer will move in a way so that sum is zero*/
/*Here is the code*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1])
                        left++;
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                }
                else if(sum < 0)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
        return ans;
    }
};

/*Well this is the 2nd question where i saw runtime past 100ms hmm not an optimal solution*/
/*No GPT paste here it spat out some code about bit manipulation only using 2 bits per value using there frequency or what not
I didn't understand it properply look like I am still to dumb to process it :( */
