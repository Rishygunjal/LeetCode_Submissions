class Solution {

bool condition(vector<int>& nums, int n, int target){
    return nums[n]>=target;
}

public:
    int search(vector<int>& nums, int target) {
        if(nums[nums.size()-1]<target || nums[0]>target) return -1;
        int hi=nums.size(),lo=-1;
        while(lo+1<hi){
            cout<<lo<<" "<<hi<<" "<<endl;
            int mid = lo + floor((hi-lo)/2);
            cout<<mid<<endl;
            if(condition(nums,mid,target)){
                hi=mid;
            }else{
                lo=mid;
            }
        }

        if(nums[hi]==target) return hi;
        else return -1; 
    }
};