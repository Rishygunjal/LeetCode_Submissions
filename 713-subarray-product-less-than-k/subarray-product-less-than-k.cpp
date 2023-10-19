class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0,j=0,prod=1,ans=0,n=nums.size();
        for(int j=0;j<n;j++){
            prod*=nums[j];
            // j++;
            cout<<prod<<"prod"<<endl;
            while(i<=j && prod>=k) {
                prod=prod/nums[i];
                i++;
            }
            ans += j-i+1;
            cout<<j<<i<<endl;
        }
        return ans;
    }
};