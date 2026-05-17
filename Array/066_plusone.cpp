/*My approach didnt even work it was to get the number form the array and add one to it*/
/*Short Sight on my part was that i didnt consider carry over and the 129 that has to be 130 went to 1210 instead*/
/*Second one was that i didnt consider the limit of the long long data type*/
/*Passed all test cases that are available for testing but failed all the one with carry over in submission*/
/*Here it is*/

/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long num = 0;

        int power = 0;

        // Convert array to number
        for(int i = digits.size() - 1; i >= 0; i--) {

            num += digits[i] * pow(10, power);

            power++;
        }

        // Add 1
        num++;

        vector<int> result;

        // Special case
        if(num == 0) {
            result.push_back(0);
            return result;
        }

        // Convert number back to digits
        while(num > 0) {

            result.push_back(num % 10);

            num /= 10;
        }

        // Reverse result
        reverse(result.begin(), result.end());

        return result;
    }
};
*/

/*This one GPT finally improved my code here the issue about the carry over is solved*/
/*And this is where i find abou the limit of long long*/
/*
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        long long num = 0;
        long long multiplier = 1;

        for(int i = digits.size() - 1; i >= 0; i--) {

            num += digits[i] * multiplier;

            multiplier *= 10;
        }

        num++;

        vector<int> result;

        while(num > 0) {

            result.push_back(num % 10);

            num /= 10;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
*/

/*Both of these dint passed the submission criteria ;(*/

/*Here is the GPT one*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        for(int i = digits.size() - 1; i >= 0; i--) {

            if(digits[i] < 9) {

                digits[i]++;
                return digits;
            }

            digits[i] = 0;
        }

        digits.insert(digits.begin(), 1);

        return digits;
    }
};
