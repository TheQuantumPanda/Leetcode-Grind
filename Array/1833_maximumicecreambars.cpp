/*Well here we go again my approch was to sort the array the accending order
and get the number of additions to get the number of ice cream*/

/*Here is the code*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int cost : costs) {
            if (coins < cost) break;
            coins -= cost;
            count++;
        }
        return count;
    }
};

/*Pasted the code in gpt along with my thoughts got to it is the most slowet possible approch
Well i did see the memory usage was in 100mb range and runtime was of also 4ms
Anyways GPT suggested to use frequnency and count that*/

/*Here is the GPT code*/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxCost + 1, 0);
        for(int cost : costs) {
            freq[cost]++;
        }
        int bars = 0;
        for(int price = 1; price <= maxCost; price++) {
            if(freq[price] == 0)
                continue;
            int canBuy = min(freq[price], coins / price);
            bars += canBuy;
            coins -= canBuy * price;
            if(coins < price)
                continue;
        }
        return bars;
    }
};


/*Well this just go ahead and shows how much I dont know. Can't do anything when I don't a concept
But now I know will see if it clicks when same type of question comes up*/
