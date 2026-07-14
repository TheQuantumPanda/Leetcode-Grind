/*Well another hash map question need to validate a sudoku table
will use a unordered map to do so will make three maps
rows cols and boxes by rules of sudoku a value can't be repeated in a 
row column or a 3x3 box*/
/*Here is the code*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++) {
                char num = board[i][j];
                int box = (i / 3 ) * 3 + (j / 3);
                
                if (num == '.') {
                    continue;
                }

                if (rows[i].count(num)) {          // -|
                    return false;                  //  |
                }                                  //  |
                if (cols[j].count(num)) {          //  |
                    return false;                  //  |<----- found value in anyone means rule is broken
                }                                  //  |
                if (boxes[box].count(num)){        //  |
                    return false;                  //  |
                }                                  // _|

                rows[i].insert(num);
                cols[j].insert(num);
                boxes[box].insert(num);
            }
        }

        return true;                              // <--- All ok
    }
};
/*It is a unordered set not map diffrence between the two
unordered map when need something in key-value pair sort of
unordered set when only want to check existence like in this question*/
/*GPT used the same sort of ideology but went with bit wise manipulations again :(*/

/*Here is the code*/

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9,0),col(9,0),box(9,0);
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                int val = board[i][j] - '0';
                int mask = 1 << val;
                int b = (i/3) * 3 + (j/3);
                if((row[i] & mask) || (col[j] & mask) || (box[b] & mask))
                    return false;
                row[i] = row[i] | mask;
                col[j] = col[j] | mask;
                box[b] = box[b] | mask;
            }
        }
        return true;
    }
};
*/
