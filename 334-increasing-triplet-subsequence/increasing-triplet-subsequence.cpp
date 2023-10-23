class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int maxi1=INT_MIN,maxi2=INT_MIN,n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]>maxi1){
                maxi1 = nums[i];
            }
            if(nums[i]==maxi1) continue;
            if(nums[i]<maxi1) {
                if(maxi2!=INT_MIN) {
                    if(nums[i]<maxi2){
                        return 1;
                    }else maxi2 = nums[i]; 
                }
                else {
                    maxi2 = nums[i];
                }
            }
        }
        return 0;
    }
};