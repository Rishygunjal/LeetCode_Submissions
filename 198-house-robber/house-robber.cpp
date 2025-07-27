class Solution {

int solve(vector<int>& nums, int i,vector<int>& dp){
    if(i>=nums.size()) return 0;
    cout<<i<<endl;
    if(dp[i]!=-1) return dp[i];

    int v1 = solve(nums,i+1,dp);
    int v2 = nums[i]+solve(nums,i+2,dp);
    dp[i]=max(v1,v2);
    return dp[i];
}

public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};