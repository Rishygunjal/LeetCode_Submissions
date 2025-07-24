class Solution {

int solve(int n, int i, vector<int> &dp){
    if(i<0) return 0;

    if(i<=1) return 1;

    if(dp[i]!=-1) return dp[i];

    return dp[i]=solve(n,i-1,dp)+solve(n,i-2,dp);
}

public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i]=-1;
        }
        return solve(n,n,dp);
    }
};