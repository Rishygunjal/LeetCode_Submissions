class Solution {

bool condition1(vector<int>& nums, int mid){
    return nums[mid]<=nums[nums.size()-1];
}

bool condition2(vector<int>& nums, int mid, int target){
    return nums[mid]>target;
}

public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==1){
            if(nums[0]==target) return 0;
            return -1;
        } 
        if(nums[0]<nums[nums.size()-1]) {
            if(nums[0]>target || nums[nums.size()-1]<target) return -1;
            int hi=nums.size(),lo=-1;
            while(lo+1<hi){
                int mid = lo + floor((hi-lo)/2);
                if(condition2(nums,mid,target)){
                    hi=mid;
                }else{
                    lo=mid;
                }
            }

            if(nums[hi-1]==target) return hi-1;
            else return -1;
        }
        int n=nums.size(),hi=n,lo=-1;
        while(lo+1<hi){
            int mid = lo + floor((hi-lo)/2);
            if(condition1(nums,mid)){
                hi=mid;
            }else{
                lo=mid;
            }
        }

        cout<<"hi "<<hi<<nums[n-1]<<target<<endl;

        if(nums[n-1]>=target){
            cout<<"wef4eeg4ef"<<endl;
            lo=hi-1,hi=n;
            if(nums[lo+1]>target || nums[hi-1]<target) return -1;
            while(lo+1<hi){
                int mid = lo + floor((hi-lo)/2);
                cout<<lo<<" "<<mid<<" "<<hi<<endl;
                if(condition2(nums,mid,target)){
                    hi=mid;
                }else{
                    lo=mid;
                }
            }
            cout<<"2hi "<<hi<<endl;
            if(nums[hi-1]==target) return hi-1;
            else return -1;
        }else{
            lo=-1;
            if(nums[lo+1]>target || nums[hi-1]<target) return -1;
            while(lo+1<hi){
                int mid = lo + floor((hi-lo)/2);
                if(condition2(nums,mid,target)){
                    hi=mid;
                }else{
                    lo=mid;
                }
            }
            if(nums[hi-1]==target) return hi-1;
            else return -1;
        }
    }
};