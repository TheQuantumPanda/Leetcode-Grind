/*Here is the first hard question I have attempted*/
/*The question isn't difficult i have to merge and sort two arrays and pick the mid element*/

/*Here is the code*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0;
        int j = 0;
        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] <= nums2[j])
                merged.push_back(nums1[i++]);
            else
                merged.push_back(nums2[j++]);
        }
        while(i < nums1.size())
            merged.push_back(nums1[i++]);
        while(j < nums2.size())
            merged.push_back(nums2[j++]);
        int total = merged.size();
        if(total % 2 == 1)
        {
            return merged[total / 2];
        }
        else
        {
            return (merged[total / 2] + merged[total / 2 - 1]) / 2.0;
        }
    }
};

/*Well the runtime is 5ms and memory used is 102 MB approx*/
/*Shouldn't have ingored the part where it says O(log(m+n))*/
/*Instead of doing sorting of a merged array better explaination
imagine a cut placed on both arrays where last element of left array is compared with first element of right array
Visual nums1 [1,2,3] nums2 [4,5,6]
Imginary Cut
[1,2, | 3]
[4, | 5,6]
left array [1,2,4] right array [3,5,6]
compare 4 and 3, 4 is bigger than 3 imaginary cut changes and this repeats untill last elemnt of left is smaller than
first element of right*/
/*Here is the GPT code*/

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        while(left <= right)
        {
            int partition1 = (left + right) / 2;
            int partition2 = (m + n + 1) / 2 - partition1;
            int maxLeft1 =
                (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int minRight1 =
                (partition1 == m) ? INT_MAX : nums1[partition1];
            int maxLeft2 =
                (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int minRight2 =
                (partition2 == n) ? INT_MAX : nums2[partition2];
            if(maxLeft1 <= minRight2 &&
               maxLeft2 <= minRight1)
            {
                if((m + n) % 2 == 0)
                {
                    return (max(maxLeft1, maxLeft2) +
                            min(minRight1, minRight2)) / 2.0;
                }
                else
                {
                    return max(maxLeft1, maxLeft2);
                }
            }
            else if(maxLeft1 > minRight2)
            {
                right = partition1 - 1;
            }
            else
            {
                left = partition1 + 1;
            }
        }
        return 0.0;
    }
};
*/
