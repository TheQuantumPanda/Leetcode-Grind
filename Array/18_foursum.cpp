/*Well the question is same as three sum just thet in three sum i had find triplet
whose sum equals to zero here i have to find the target value, my approach fix two values
then go with the same left right pointer approach*/
/*Here is the code*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums [i-1]){
                continue;
            }
            for(int j = i+1; j < n-2; j++){
                if(j > (i+1) && nums[j] == nums [j-1]){
                    continue;
                }
                int left = j+1;
                int right = n-1;
                while (left < right){
                    int sum = nums[i]+nums[j]+nums[left]+nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums [left - 1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
/*Well got the error about reaching the limit of int data type why does that test case even exist
My logic correct why it failed due to a abusrdly fking large value. Now to change the sum data type to long long*/
/*New thing learned it is long long sum = (long long) nums[i]+nums[j]+nums[left]+nums[right] not
long long sum = long long (nums[i]+nums[j]+nums[left]+nums[right])*/

/*Here is the code*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-3; i++){
            if (i > 0 && nums[i] == nums [i-1]){
                continue;
            }

            for(int j = i+1; j < n-2; j++){
                if(j > (i+1) && nums[j] == nums [j-1]){
                    continue;
                }

                int left = j+1;
                int right = n-1;
                
                while (left < right){
                    long long sum = (long long)nums[i]+nums[j]+nums[left]+nums[right];

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums [left - 1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                    else if(sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
        }

        return ans;

    }
};

/*GPT spat the same code whit some extra steps the does prunning so after sorting we
take max and min value of quad values mainly first 4 and first and last three then compare the target to them
same with second loop this minimizes the the searches hmm noice*/

/*Here is the code*/

/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            long long minSum =
                (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (minSum > target)
                break;
            long long maxSum =
                (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (maxSum < target)
                continue;
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                minSum =
                    (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (minSum > target)
                    break;
                maxSum =
                    (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (maxSum < target)
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l) {
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    } else if (sum < target) {
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};
*/
