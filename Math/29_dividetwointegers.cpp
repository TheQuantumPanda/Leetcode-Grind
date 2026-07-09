/*Hmm NO multiplication divison or MOD*/
/*Only options i see the elementry maths substract one by one -_-*/
/*Here is the code*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long count = 0;
        long long dvs = llabs((long long)divisor);
        long long dvd = llabs((long long)dividend);
        bool negative = (dividend < 0) ^ (divisor < 0);
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        while(dvd >= dvs){
            dvd -= dvs;
            count++;
        }
        if(negative){
            count = -count;
        }
        return count;
    }
};
/*These damn test cases the one and only test case failing(knew because leetcode say 993/994) is because 
Dividend is the nearing the limits of 32 but signed integer and divisor is -1(this test case >-<) TLE*/
/*Well look like i to bitwise manipulation i have been putting of it for a while*/
/*1hr later Here is the code*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long count = 0;
        long long multiple = 1;
        long long dvs = llabs((long long)divisor);
        long long dvd = llabs((long long)dividend);
        bool negative = (dividend < 0) ^ (divisor < 0);
        if(dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        while (dvd >= dvs){
            long long temp = dvs;
            long long multiple = 1;
            while ((temp << 1) <= dvd){
                temp = temp << 1;
                multiple = multiple << 1;
            }
            dvd = dvd - temp;
            count = count +multiple;
        }
        if(negative){
            count = -count;
        }
        return count;
    }
};
/*Bitwise operation are complex than it seems here i turned calculation in mutiple something like divisor*some power of 2*/
