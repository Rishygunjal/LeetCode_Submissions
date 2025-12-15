class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<k;i++){
            ans-=nums[i];
            ans+=nums[nums.size()-1-i];
            // cout<<ans<<endl;
        }
        return ans; 
    }
};