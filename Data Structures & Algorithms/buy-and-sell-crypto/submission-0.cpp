class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
int minPurchasingPrice = prices[0];
int maxProfit = 0;


for(int i = 1; i<n; i++){
    int sellingPrice = prices[i];
    // i sell when the selling price > purchasing price
   
    if(sellingPrice < minPurchasingPrice){
        minPurchasingPrice = sellingPrice;
    }

    else{
        int profit = sellingPrice - minPurchasingPrice;
        maxProfit = max(maxProfit, profit);
    }
}
return maxProfit;

    }
};



