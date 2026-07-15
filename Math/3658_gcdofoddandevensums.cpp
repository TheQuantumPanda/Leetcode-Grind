/*THe questions is an easy i just have to implement GCD in code*/
/*Here is the code*/
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 1;
        int sumEven = 2;
        int remd;

        for (int i = 0; i < n; i++){
            sumOdd = sumOdd + 2;
            sumEven = sumEven + 2;
        }

        while (remd != 0) {
            if (sumOdd > sumEven) {
                sumOdd = sumEven;
                sumEven = remd;

                remd = (sumOdd % sumEven);
            }
            else {
                sumEven = sumOdd;
                sumOdd = remd;

                remd = (sumEven % sumOdd);
            }
        }

        if (sumOdd > sumEven) {
            return sumEven;
        }
        else {
            return sumOdd;
        }
    }
};
/*Got address sanitization error i am accessing something non-existent huh*/
/*Huh can't do this approach now have integer overflow :(*/
/*Here is the code anyways*/
/*
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumOdd = 1;
        int sumEven = 2;
        int remd;

        for (int i = 0; i < n; i++){
            sumOdd = sumOdd + 2;
            sumEven = sumEven + 2;
        }

        if (sumOdd > sumEven) {
            int remd = (sumOdd % sumEven);
        }
        else {
            int remd = (sumEven % sumOdd);
        }

        while (remd != 0) {
            if (sumOdd > sumEven) {
                sumOdd = sumEven;
                sumEven = remd;

                remd = (sumOdd % sumEven);
            }
            else {
                sumEven = sumOdd;
                sumOdd = remd;

                remd = (sumEven % sumOdd);
            }
        }

        if (sumOdd > sumEven) {
            return sumEven;
        }
        else {
            return sumOdd;
        }
    }
};
*/
/*Well another option to calculate summodd and even is n*n and n(n+1)*/
/*Here is the code*/
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumOdd = (long long)n*n;
        long long sumEven = (long long) n*(n+1);
        long long rem;

        if (sumOdd > sumEven) {
            rem = (sumOdd % sumEven);
        }
        else {
            rem = (sumEven % sumOdd);
        }

        while (rem != 0) {
            if (sumOdd > sumEven) {
                sumOdd = sumEven;
                sumEven = rem;

                rem = (sumOdd % sumEven);
            }
            else {
                sumEven = sumOdd;
                sumOdd = rem;

                rem = (sumEven % sumOdd);
            }
        }

        if (sumOdd > sumEven) {
            return sumEven;
        }
        else {
            return sumOdd;
        }
    }
};

/*A very fking imp observation sumOdd is n*n and sumeven is n*(n+1)
expanding sumEven n*n + n so smallest possible integer is always going to be n
the fking solution is just return n ;^; i wasted like 20 mins just to figure out
solution is return n*/
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
/*Gotta study class 9th maths first ;-;*/
