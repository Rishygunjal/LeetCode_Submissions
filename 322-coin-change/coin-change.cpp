class Solution {

int solve(vector<vector<int>>& dp, vector<int>& coins, int amount, int i){

    // cout<<amount<<" amount "<<i<<" i "<<endl;

    //base cases
    if(amount==0) return 0;
    if(amount<0 || i>=coins.size()) return INT_MAX-10;

    if(dp[i][amount]!=-1) return dp[i][amount];

    int case1 = 1 + solve(dp,coins,amount-coins[i],i);
    int case2 = solve(dp,coins,amount,i+1);
    // cout<<case1<<"case1"<<endl;
    if(case1>=(INT_MAX-100) && case2>=(INT_MAX-100)){
        return dp[i][amount]=INT_MAX-10;
    }else if(case1>=(INT_MAX-100) && case2<(INT_MAX-100)){
        return dp[i][amount]=case2;
    }else if(case1<(INT_MAX-100) && case2>=(INT_MAX-100)){
        return dp[i][amount]=case1;
    }else{
        return dp[i][amount]=min(case1,case2);
    }

}


public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(12,vector<int> (amount+1,-1));
        int ans= solve(dp,coins,amount,0);
        if(ans>=(INT_MAX-100)) return -1;
        else return ans;
    }
};