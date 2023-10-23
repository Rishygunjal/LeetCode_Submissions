class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int maxi=INT_MIN,n=nums.size();
        // unordered_map<int,bool> m;
        // for(int i=n-1;i>=0;i--){
        //     if(nums[i]>=maxi) {
        //         maxi=nums[i];
        //         m[i]=0;
        //     }else {
        //         m[i]=1;
        //     }
        // }
        // for(int i=0;i<)
        int ctr=1,maxi1=INT_MIN+1,maxi2=INT_MIN,n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(nums[i]>maxi1){
                maxi1 = nums[i];
                // maxi2 = maxi1;
            }else if(nums[i]==maxi1){
                continue;
            }else if(nums[i]>=maxi2){
                maxi2 = nums[i];
            }else{
                return 1;
            }
        }
        return 0;
    }
};