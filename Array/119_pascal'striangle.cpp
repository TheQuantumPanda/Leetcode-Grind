/*Well went with the brute force method again made the whole triangle to get the solution*/

/*Here is the solution*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        for(int i = 0; i <= rowIndex; i++) {
            vector<int> row(i + 1, 1);
            for(int j = 1; j < i; j++
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};

/*GPT solution*/

/*
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for(int i = 2; i <= rowIndex; i++) {
            for(int j = i - 1; j >= 1; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};
*/

/*Don't have to much to write am on the move will have very less time to do questions*/
