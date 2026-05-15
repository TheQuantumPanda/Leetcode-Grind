/* My Approach to check every possibilty*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {

            int complement = target - nums[i];

            if(mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

/* I dont know why GPT went with hash map even when i said to tell me how to improve this code 
why did it scratch the later part??
but it was the better result*/

/*Better Solution*/

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int complement = target-nums[i];
            if(mp.find(complement) != mp.end()){
                return{mp[complement],i};
            }
            mp[nums[i]]=i;
        }
        return {};
    }
};
*/
