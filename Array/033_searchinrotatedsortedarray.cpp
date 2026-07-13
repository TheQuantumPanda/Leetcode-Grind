/*This questions is just if could be just done with comparing every element for ans
but we need to have O(log n) time*/
/*If I hadn't seen topics i would have probaly spent 30 mins more tring to figure out
where to proceed since this didnt work anyway binary search that is divide and search*/

/*Here is the code*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left+right)/2;
        while (left<=right) {
            mid = (left + right)/2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if(target >= nums[left] && target < nums[mid]){
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else{
                if (target > nums[mid] && target <= nums[right]){
                    left = mid + 1;
                }
                else {
                    right = mid -1;
                }
            }
        }
        return -1;
    }
};

/*Keep dividing untill mid is the correct ans*/
