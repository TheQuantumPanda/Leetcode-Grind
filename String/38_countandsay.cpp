/*Well Well the questions is a bit tricky to understand at first
the terminology are there only to confuse if simple reading 
Example '111' is read as 3 1's thats it whatever about RLE is given
is given only for sole purpose to make you forget to read out aloud*/
/*Anyways next part is the intersting part is if it is
something like 23321511 then it wont be 31222315 but 
122312111521 that is consecutive only need to make sure that loop breaks
after it is not consecutive*/

/*Here is the code*/

class Solution {
public:
    string countAndSay(int n) {
        string current = "1";

        if (n == 1) {
            return current;
        }

        for (int i = 2; i <= n; i++) {
            string next = "";
            int j = 0;
            
            while ( j < current.length()) {
                int count = 1;
                while ( (j + 1) < current.length() && current[j+1] == current[j] ){
                    count++;
                    j++;
                }
                next = next + to_string(count) + current[j];
                j++;
            }
            current = next;
        }

        return current;
    }
};
/*It's been a while when i saw my code in in the bottom 5% according to stat
most people have done it under 3 ms while mine takes almost 60ms ;-;
Well I dont have idea currently where to begin optimizing it*/
/*Went to ChatGPT for optimizations it blurted out a brand new code
basically it does the same thing if taken under a bigger umbrella but overall
there is a just a single loop insted of 3 and it traverse the string
which i avoided and uses conditions to same result but lower runtime*/

/*Here is the code*/

/*
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev="1";
        for(int i=2; i<=n; i++){
            string next;
            char a=prev[0];
            int count=1;
            for(int j=1; j<prev.size(); j++){
                if(prev[j]==a){
                    count++;
                }
                else{
                    next.push_back((char)count+'0');
                    next.push_back(a);
                    a=prev[j];
                    count=1;
                }
            }
            if(count!=0){
                next.push_back((char)count+'0');
                next.push_back(a);
            }
            prev=next;
        }
        return prev;
    }
};
*/
