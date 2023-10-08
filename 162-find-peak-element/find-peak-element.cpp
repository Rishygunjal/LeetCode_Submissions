class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1) return 0;
        nums.insert(nums.begin(),-INT_MAX);
        nums.push_back(-INT_MAX);
        int n = nums.size(),l=1,r=n-2;

        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid-1]<=nums[mid] && nums[mid]>=nums[mid+1]) return mid-1;
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                if(nums[l]>=nums[mid] && mid!=l){
                    r = mid-1;
                }else if(nums[r]<nums[mid]){
                    l = mid+1;
                }else{
                    l = mid+1;
                }
            }
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]){
                if(nums[r]>=nums[mid]){
                    l = mid+1;
                }else {
                    r = mid-1;
                } 
            }else{
                l=mid+1;
            }
        }

        return l-1;
    }
};