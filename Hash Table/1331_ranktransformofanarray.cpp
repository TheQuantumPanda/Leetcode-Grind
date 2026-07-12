/*Question asks for an array that consist of rank based on orignal array
Approach duplicate the array sort it assign rank and save in hash map
next compare the values in  hash map to switch values in orignal array to ranks*/
/*Here is the code*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if (arr.empty()){
            return {};
        }
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> rank;
        int currentRank = 1;
        rank[temp[0]] = 1;
        for (int i = 1; i < temp.size(); i++) {
            if(temp[i] != temp[i-1]){
                currentRank++;
            }
            rank[temp[i]] = currentRank;
        }
        for (int i = 0; i < arr.size(); i++){
            arr[i]=rank[arr[i]];
        }
        return arr;
    }
};

/*Failed on first run itself added a blank array check*/

/*Here is the approach suggested by GPT
The approach suggested by GPT is to store index of the orignal array and then assign ranks based on values*/

/*Here is the code*/
/*
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return {};
        vector<int> res(n);
        vector<pair<int,int>> temp(n);
        for (int i = 0; i < n; i++) temp[i] = {arr[i],i};
        sort(temp.begin(),temp.end(),[](pair<int,int> &a , pair<int,int> &b) {
            return a.first < b.first;
        });
        res[temp[0].second] = 1;
        for (int i = 1; i < n; i++) {
            if (temp[i].first == temp[i - 1].first) res[temp[i].second] = res[temp[i - 1].second];
            else res[temp[i].second] = res[temp[i - 1].second] + 1;
        }
        return res;
    }
};
*/
