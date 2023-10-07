class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,n=nums.size(),r=n-1;

        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[l]>nums[r]){
                if(nums[mid]>=nums[l]){
                    l=mid+1;
                }else{
                    r = mid;
                }
            }else{
                return nums[l];
            }
        }
        return nums[l];
    }
};