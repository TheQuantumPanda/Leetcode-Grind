/*The question is easy one i just need to find the substring i dont even need to check for all values one match 
1 substring confirmed*/
/*I used three loops one to traverse the array on inside it to traverse the given word in the second loop
the second loop is initilized in a way to check for every possible position and to do so I use a while loop
and after it a if loop to make sure if the complete string is found*/
/*Here is the code*/
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (int i = 0; i < patterns.size(); i++) {
            for (int j = 0; j <= word.size() - patterns[i].size(); j++) {
                int k = 0;
                while (k < patterns[i].size() &&
                       word[j + k] == patterns[i][k]) {
                    k++;
                }
                if (k == patterns[i].size()) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
/*Boom got a runtime error in this part for (int j = 0; j <= word.size() - patterns[i].size(); j++) the issue
this condtion word.size() - patterns[i].size() it returns a unsigned integer so if something comes negative
due to it beign unsigned it turn into a huge positive number that in turns tries to access far beyond the length
of the word hence AddressSanitizer Error*/
/*This is easy heh*/
/*Asked GPT what can be improved in order to fix the error it modified the condition of the second loop*/
/*
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        for (int i = 0; i < patterns.size(); i++) {
            for (int j = 0; j + patterns[i].size() <= word.size(); j++) {
                int k = 0;
                while (k < patterns[i].size() &&
                       word[j + k] == patterns[i][k]) {
                    k++;
                }
                if (k == patterns[i].size()) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
/*Now GPT used the inbuilt funtion to do the same here is the code in any case*/
/*
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int count = 0;
        for(string &s : patterns)
        {
            if(word.find(s) != string::npos)
                count++;
        }

        return count;
    }
};
*/
