class Solution {

bool condition(vector<int>& nums, int mid){
    return nums[mid]<=nums[nums.size()-1];
}

public:
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1]) return nums[0];
        int n=nums.size(),hi=n,lo=-1;
        while(lo+1<hi){
            int mid = lo + floor((hi-lo)/2);
            if(condition(nums,mid)){
                hi=mid;
            }else{
                lo=mid;
            }
        }
        return nums[hi];
    }
};