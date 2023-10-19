class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,n=nums.size(),ans=0,t=0;
        for(int j=0;j<n;j++){
            t+=nums[j]==0;
            while(t>1){
                t-=nums[i++]==0;
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};