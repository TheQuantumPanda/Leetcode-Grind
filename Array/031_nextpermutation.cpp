/*Well didnt understood at first what to went with a approch with getting all possible combination then finding in it
but it takes like 30ms that gives TLE didnt work now tried to find the point where nums[i]<nums[i+1] this will be the point
where the change need to happen*/

/*Here is the code*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 2;
        int pivot = -1;
        while (n>=0) {
            if (nums[n+1] > nums[n]){
                pivot = n;
                break;
            }
            n--;
        }
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int i = nums.size() - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        reverse(nums.begin()+pivot+1, nums.end());
    }
};
