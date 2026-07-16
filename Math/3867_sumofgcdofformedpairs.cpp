/*My approach simple follow everything dont use your own brain*/
/*Here is the code*/
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        long long max = nums[0];
        long long sum = 0;
        vector<int> prefixGcd(n);

        for (int i = 0; i < n; i++ ) {
            if (nums[i] > max) {
                max = nums[i];
            }
            
            long long a = nums[i];
            long long b = max;
            
            while (b != 0) {
                long long temp = b;
                b = a % b;
                a = temp;
            }

            prefixGcd[i] = a;
        }

        for (int i = 0; i < (n - 1); i++) {
            long long minIndex = i;

            for (int j = i; j < n; j++) {
                if (prefixGcd[j] < prefixGcd[minIndex]) {
                    minIndex = j;
                }
            }

            long long temp = prefixGcd[minIndex];
            prefixGcd[minIndex] = prefixGcd[i];
            prefixGcd[i] = temp;
        }

        for (int i = 0; i < (n / 2); i++){
            if (i == ((n + 1)/2)) {
                continue;
            }

            long long a = prefixGcd[i];
            long long b = prefixGcd[n - 1 - i];

            while (b != 0) {
                long long temp = b;
                b = a % b;
                a = temp;
            }

            sum = sum + a;
        }

        return sum;
    }
};
/*;^; shoulda used my brain the sort i implement is causing TLE*/
/*New code*/
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        long long max = nums[0];
        long long sum = 0;
        vector<int> prefixGcd(n);

        for (int i = 0; i < n; i++ ) {
            if (nums[i] > max) {
                max = nums[i];
            }
            
            long long a = nums[i];
            long long b = max;
            
            while (b != 0) {
                long long temp = b;
                b = a % b;
                a = temp;
            }

            prefixGcd[i] = a;
        }

        sort(prefixGcd.begin(), prefixGcd.end());

        for (int i = 0; i < (n / 2); i++){
            if (i == ((n + 1)/2)) {
                continue;
            }

            long long a = prefixGcd[i];
            long long b = prefixGcd[n - 1 - i];

            while (b != 0) {
                long long temp = b;
                b = a % b;
                a = temp;
            }

            sum = sum + a;
        }

        return sum;
    }
};

/*I didn't knew this was allowed the use of inbuilt function*/
/*Here is the GPT code*/
/*
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int xMax=0, n=nums.size();
        for(int& x: nums){
            xMax=max(x, xMax);
            x=gcd(x, xMax);
        }
        sort(nums.begin(), nums.end());
        long long sum=0;
        for(int l=0, r=n-1; l<r; l++, r--)
            sum+=gcd(nums[l], nums[r]);
        return sum;
    }
};
*/
