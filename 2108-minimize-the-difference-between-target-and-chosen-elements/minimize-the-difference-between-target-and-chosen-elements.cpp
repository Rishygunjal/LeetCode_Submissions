class Solution {

    int solve(vector<vector<int>>& mat, int target, int i){
        if(i==mat.size()){
            return abs(target);
        }

        int ans=INT_MAX;

        for(int j=0;j<mat[0].size();j++){
            ans = min(ans,solve(mat,target-mat[i][j],i+1));
        }

        return ans;
    }

    // int solveMem(vector<vector<int>>& mat, int target, int i,vector<vector<int>>& dp){
    //     if(i==mat.size()){
    //         return abs(target);
    //     }

    //     if(dp[target][i]!=-1) return dp[target][i];

    //     int ans=INT_MAX;

    //     for(int j=0;j<mat[0].size();j++){
    //         ans = min(ans,solveMem(mat,target-mat[i][j],i+1,dp));
    //     }

    //     return dp[target][i]=ans;
    // }

    long long solveMem(vector<vector<int>>& mat, long long target, int i,int sum,vector<vector<long long>>& dp){
        // cout<<i<<target<<endl;
        if(i==mat.size()){
            return abs(target-sum);
        }

        if(dp[sum][i]!=-1) return dp[sum][i];

        long long ans=INT_MAX;

        for(int j=0;j<mat[i].size();j++){
            // cout<<j<<endl;
            ans = min(ans,solveMem(mat,target,i+1,sum+mat[i][j],dp));
        }

        return dp[sum][i]=ans;
    }

public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size(),m=mat[0].size();
        // return solve(mat,target,0);
        vector<vector<long long>> dp(70*70+1,vector<long long> (n+2,-1));
        return solveMem(mat,target,0,0,dp);
    }
};