class Solution {

int solve(vector<int> nums, int i, int diff){
    if(i==nums.size()-1) return 0;

    int ans=0;
    for(int j=i+1;j<nums.size();j++){
        cout<<diff<<nums[j]-nums[i]<<i<<j<<endl;
        if(nums[j]-nums[i]==diff) ans = max(ans,1 + solve(nums,j,diff));
        else ans = max(ans,2 + solve(nums,j,nums[j]-nums[i])); 
    }
    return ans; 
}

public:
    int longestArithSeqLength(vector<int>& nums) {
        // return solve(nums,0,INT_MAX);
        int n=nums.size(),ans=0;
        vector<vector<int>> dp(nums.size()+1,vector<int> (2000,0));

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dp[j][nums[j]-nums[i]+1000] = 1 + dp[i][nums[j]-nums[i]+1000];
                ans = max(ans,dp[j][nums[j]-nums[i]+1000]);
            }
        }

        return ans+1;
        
    }
};