class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size(),ans=0,t=0,t1=0;
        for(j=0;j<n;j++){
            t+=nums[j]==0;
            // t1+=nums[j]==1;
            while(i<=j && t>k){
                cout<<i<<endl;
                t-=nums[i++]==0;
                // t1-=nums[i]==1;
                // i--;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};