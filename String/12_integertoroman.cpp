/*Another day another question the value that needs to be returned is a string
The premise is easy i need two string of same size one contains numerical values other one has roman values
a while is used with condtion num>=value[i] this will give the desired number when roman values repeats*/
/*Here is the code*/
class Solution {
public:
string intToRoman(int num) {
vector<int> values = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
string answer="";
for(int i = 0; i < values.size(); i++)
{
while(num >= values[i])
{
answer += symbols[i];
num -= values[i];
}
}
return answer;
}
};
/*Remembered about tuples that store data in key value pair that is better fit than two arrays*/
/*Here is the code with tuple*/
class Solution {
public:
    string intToRoman(int num) {
        vector<tuple<int, string>> roman = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        string ans = "";
        for (auto &t : roman) {
            int value = get<0>(t);
            string symbol = get<1>(t);
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }
        return ans;
    }
};
/*Somehow tuples is worse than two arrays*/
/*ChatGPT went with the same approach but the result is better than both of mine
it used something called pair although from what I can see is that pair and tupple
both are same then most probably it is how they store and access data at memory level
or maybe how the computer interprets it will find out how on google*/
/*Here is the code*/

/*
class Solution {
public:
    string intToRoman(int num) {
        static const pair<int,string> roman[] = {
            {1000,"M"}, {900,"CM"}, {500,"D"}, {400,"CD"},
            {100,"C"}, {90,"XC"}, {50,"L"}, {40,"XL"},
            {10,"X"}, {9,"IX"}, {5,"V"}, {4,"IV"}, {1,"I"}
        };
        string ans;
        for (auto &[value, symbol] : roman) {
            while (num >= value) {
                ans += symbol;
                num -= value;
            }
        }
        return ans;
    }
};
*/
