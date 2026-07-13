/*Well well continuing from yesterday the questions ask for O(log n) time
So binanry search it is and it need two positions so two binary searches*/
/*The implementation of binanry from yesterday is definitly easier*/

/*Here is the code*/

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int first = -1;
        while ( left <= right ) {
            int mid = (left + right)/2;       
            if ( nums[mid] == target) {
                first = mid;
                right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return first;
    }
    int findLast(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int last = -1;
        while ( left <= right ) {
            int mid = (left + right)/2;       
            if ( nums[mid] == target) {
                last = mid;
                left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        if (first == -1) {
            return {-1, -1};
        }
        int last = findLast(nums,target);
        return {first,last};
    }
};
