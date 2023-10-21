class Solution {

int calMaxProfit(vector<int>& prices, int i, bool hold){
    if(i>=prices.size()) return 0;

    if(!hold){
        int buy = - prices[i] + calMaxProfit(prices,i+1,1);
        int skip = calMaxProfit(prices,i+1,0);
        return max(buy,skip);
    }else{
        int sell = prices[i] + calMaxProfit(prices,i+2,0);
        int skip = calMaxProfit(prices,i+1,1);
        return max(sell,skip);
    }
}

int calMaxProfitMem(vector<int>& prices, int i, bool hold,vector<vector<int>>& dp){
    if(i>=prices.size()) return 0;

    if(dp[i][hold]!=-1) return dp[i][hold];

    if(!hold){
        int buy = - prices[i] + calMaxProfitMem(prices,i+1,1,dp);
        int skip = calMaxProfitMem(prices,i+1,0,dp);
        return dp[i][hold]=max(buy,skip);
    }else{
        int sell = prices[i] + calMaxProfitMem(prices,i+2,0,dp);
        int skip = calMaxProfitMem(prices,i+1,1,dp);
        return dp[i][hold]=max(sell,skip);
    }
}

public:
    int maxProfit(vector<int>& prices) {
        // return calMaxProfit(prices,0,0);
        vector<vector<int>> dp(prices.size()+2,vector<int> (2,-1));
        return calMaxProfitMem(prices,0,0,dp);
    }
};