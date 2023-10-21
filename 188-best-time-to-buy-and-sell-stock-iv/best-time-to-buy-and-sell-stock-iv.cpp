class Solution {

int calMaxProfit(vector<int>& prices, int i, bool hold, int ctr){
    if(i>=prices.size() || ctr==0) return 0;

    if(!hold){
        int buy = - prices[i] + calMaxProfit(prices,i+1,1,ctr);
        int skip = calMaxProfit(prices,i+1,0,ctr);
        return max(buy,skip);
    }else{
        int sell = prices[i] + calMaxProfit(prices,i+1,0,ctr-1);
        int skip = calMaxProfit(prices,i+1,1,ctr);
        return max(sell,skip);
    }
}

int calMaxProfitMem(vector<int>& prices, int i, bool hold, int ctr, vector<vector<vector<int>>>& dp){
    if(i>=prices.size() || ctr==0) return 0;

    if(dp[i][hold][ctr]!=-1) return dp[i][hold][ctr];

    if(!hold){
        int buy = - prices[i] + calMaxProfitMem(prices,i+1,1,ctr,dp);
        int skip = calMaxProfitMem(prices,i+1,0,ctr,dp);
        return dp[i][hold][ctr]=max(buy,skip);
    }else{
        int sell = prices[i] + calMaxProfitMem(prices,i+1,0,ctr-1,dp);
        int skip = calMaxProfitMem(prices,i+1,1,ctr,dp);
        return dp[i][hold][ctr]=max(sell,skip);
    }
}

public:
    int maxProfit(int k, vector<int>& prices) {
        // return calMaxProfit(prices,0,0,k);
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>> (2,vector<int> (k+1,-1)));
        return calMaxProfitMem(prices,0,0,k,dp);
    }
};