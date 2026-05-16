/*Brute Force solution*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] >= target) {
                return i;
            }
        }

        return nums.size();
    }
};

/*
The GPT used binary search and the result speaks for themself the runtime might be the same
but it shows it beats 99.7% people there were always better solution it still was in the 82%+
teritory but this was interesting to see ig anyways
*/

/*GPT Solution*/

/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] < target) {
                left = mid + 1;
            }

            else {
                right = mid - 1;
            }
        }

        return left;
    }
};
*/
