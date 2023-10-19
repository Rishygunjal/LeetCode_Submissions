class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> prefix(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int i=0,n=nums.size();
        int ans =0;
        for(int j=0;j<n;j++){
            m[nums[j]]++;
            while(m[nums[j]]>1){
                m[nums[i++]]--;
            }
            ans = max(ans,prefix[j+1]-prefix[i]);
        }
        return ans;
    }
};