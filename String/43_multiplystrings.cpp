/*Well I dont see any choice expect to it the 1st grader way*/
/*
    12
__x_45__
    10       (2x5 = 10)
____5x__     (1x5 = 5)
    8x       (2x4 = 8)
___4xx__     (1x4 = 4)
--------
   540
*/
/*Also make sure that not the entire string is converted into integer
I am supposed to multiply digit by digit*/
/* Here is the code*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int loop1 = num1.length() - 1;
        vector<int> sol((num1.length() + num2.length()));
        string ans;

        while (loop1 >= 0) {
            int a = num1[loop1] - '0';
            int carry = 0;
            int loop2 = num2.length() - 1;
            while(loop2 >= 0) {
                int b = num2[loop2] - '0';
                int pos = loop1 + loop2 + 1;
                int total = sol[pos] + (a * b);

                if (total > 9){
                    sol[pos] += total % 10;
                    sol[pos - 1] +=  total / 10;
                }
                else {
                    sol[pos] = total;
                }

                loop2--;
            }
            loop1--;
        }

        for (int i = 0; i < sol.size(); i++) {
            if (sol[i] == 0 && (i+1) < sol.size() && sol[i+1] != 0){
                continue;
            }
            ans = ans + char((sol[i] + '0'));
        }

        return ans;
    }
};

/*IDK what is causing @ to appear as a value only thing I know is that adding 
0 as a string cause them to be @ instead of there poper value*/
/*Found it sol[pos] += total % 10; this is the cause*/
/*Fixed code*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int loop1 = num1.length() - 1;
        vector<int> sol((num1.length() + num2.length()));
        string ans;

        while (loop1 >= 0) {
            int a = num1[loop1] - '0';
            int carry = 0;
            int loop2 = num2.length() - 1;
            while(loop2 >= 0) {
                int b = num2[loop2] - '0';
                int pos = loop1 + loop2 + 1;
                int total = sol[pos] + (a * b);

                if (total > 9){
                    sol[pos] = total % 10;
                    sol[pos - 1] +=  total / 10;
                }
                else {
                    sol[pos] = total;
                }

                loop2--;
            }
            loop1--;
        }

        for (int i = 0; i < sol.size(); i++) {
            if (sol[i] == 0 && (i+1) < sol.size() && sol[i+1] == 0){
                continue;
            }
            ans = ans + char((sol[i] + '0'));
        }

        return ans;
    }
};

/*Fk need to something about leading zeros my conditions doesn't work is there is only 1*/
/*Here is the new logic for leading zeros*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int loop1 = num1.length() - 1;
        vector<int> sol((num1.length() + num2.length()));
        string ans;

        while (loop1 >= 0) {
            int a = num1[loop1] - '0';
            int loop2 = num2.length() - 1;
            while(loop2 >= 0) {
                int b = num2[loop2] - '0';
                int pos = loop1 + loop2 + 1;
                int total = sol[pos] + (a * b);

                if (total > 9){
                    sol[pos] = total % 10;
                    sol[pos - 1] +=  total / 10;
                }
                else {
                    sol[pos] = total;
                }

                loop2--;
            }
            loop1--;
        }

        bool started = false;

        for (int i = 0; i < sol.size(); i++) {
            if (started) {
                ans = ans + char(sol[i] + '0');
            }
            else {
                if (sol[i] != 0){
                    started = true;
                    ans = ans + char(sol[i] + '0');
                }
            }
        }

        return ans;
    }
};

/*Who tf wrote the test cases it failed on "0"*/
/*The fix is simple that's good*/

/*Here is the code*/

class Solution {
public:
    string multiply(string num1, string num2) {
        int loop1 = num1.length() - 1;
        vector<int> sol((num1.length() + num2.length()));
        string ans;

        if ( num1 == "0" || num2 == "0" ){
            return "0";
        }

        while (loop1 >= 0) {
            int a = num1[loop1] - '0';
            int loop2 = num2.length() - 1;
            while(loop2 >= 0) {
                int b = num2[loop2] - '0';
                int pos = loop1 + loop2 + 1;
                int total = sol[pos] + (a * b);

                if (total > 9){
                    sol[pos] = total % 10;
                    sol[pos - 1] +=  total / 10;
                }
                else {
                    sol[pos] = total;
                }

                loop2--;
            }
            loop1--;
        }

        bool started = false;

        for (int i = 0; i < sol.size(); i++) {
            if (started) {
                ans = ans + char(sol[i] + '0');
            }
            else {
                if (sol[i] != 0){
                    started = true;
                    ans = ans + char(sol[i] + '0');
                }
            }
        }

        return ans;
    }
};
