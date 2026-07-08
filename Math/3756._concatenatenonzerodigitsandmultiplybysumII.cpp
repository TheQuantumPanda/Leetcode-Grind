/*Continuation from the yesterday easy now need to traverse the string
I will use query index as index for loop that way i can traverse the string*/
/*Here is the code*/
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> answer;
        const int MOD = 1e9 + 7;
        for (int i = 0; i<queries.size(); i++){
            long long x = 0;
            long long sum = 0;
            
            int l = queries[i][0];
            int r = queries[i][1];

            for(int j = l; j<=r; j++){
                int digit = s[j] - '0';
                if (digit != 0) {
                    x = x*10 + digit;
                    sum = sum + digit;
                }
            }
        answer.push_back((x*sum)%MOD);
        }
    return answer;        
    }
};
/*Thought so everythings going well the failed reached the absolute limit of long long -_-*/
/*Should have read the line where it say number too big use modulo 10^9 :(
I dont know why but i went with optimizing sum value first probably fealt it easy 
but it serves only in space complexity not time*/
/*Here is the code*/
class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> answer;
        vector<int> prefix(s.size());
        const int MOD = 1e9 + 7;

        prefix[0] = s[0]-'0';

        for (int i = 1; i < s.size(); i++){
            prefix[i] = prefix[i-1];
            if(s[i] != '0'){
                prefix[i] = prefix[i] + (s[i]-'0');
            }
        }
        for (int i = 0; i<queries.size(); i++){
            long long x = 0;
            long long sum = 0;
            
            int l = queries[i][0];
            int r = queries[i][1];

            if (l==0) {
                sum = prefix[r];
            } else {
                sum = prefix[r]-prefix[l-1];
            }

            for(int j = l; j<=r; j++){
                int digit = s[j] - '0';
                if (digit != 0) {
                    x = (x*10 + digit)% MOD;
                }
            }
        answer.push_back((x*sum)%MOD);
        }
    return answer;        
    }
};
/*Always a test case first one took it to absolute limits to long long this one took it absolute time limit
Got time limit exceeded error :( */

/*Yeah not happening today took help of chat gpt and would say removing loops and doing preprocessing is
absolute brain wreking would only attempt these type of question only after I reach somewhere around 500 ques*/

/*Here is the GPT code*/

/*
class Solution {
public:
    static const int MOD = 1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> prefixSum(n);
        vector<int> countNZ(n);
        vector<long long> prefixNum(n);
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        long long num = 0;
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';
            if (digit != 0) {
                sum += digit;
                cnt++;
                num = (num * 10 + digit) % MOD;
            }
            prefixSum[i] = sum;
            countNZ[i] = cnt;
            prefixNum[i] = num;
        }
        vector<int> ans;
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long digitSum = prefixSum[r];
            if (l > 0)
                digitSum -= prefixSum[l - 1];
            long long x = prefixNum[r];
            if (l > 0) {
                int k = countNZ[r] - countNZ[l - 1];
                x = (x - prefixNum[l - 1] * pow10[k]) % MOD;
                if (x < 0)
                    x += MOD;
            }
            ans.push_back((x * digitSum) % MOD);
        }
        return ans;
    }
};
*/
