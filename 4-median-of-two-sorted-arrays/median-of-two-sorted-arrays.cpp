class Solution {

int cal(vector<int>& nums1, vector<int>& nums2, int mid){
    int c1 = upper_bound(nums1.begin(),nums1.end(),mid)-nums1.begin();
    int c2 = upper_bound(nums2.begin(),nums2.end(),mid)-nums2.begin();
    return c1+c2;
}

double solve2(vector<int>& nums1, vector<int>& nums2){
    int l=-1e6-1,r=1e6+1;
    int n = (nums1.size()+nums2.size())/2+1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(cal(nums1,nums2,mid)<n) l=mid+1;
        else r = mid;
    }

    return l;  
}

double solve1(vector<int>& nums1, vector<int>& nums2){
    int l=-1e6-1,r=1e6+1;
    int n1 = (nums1.size()+nums2.size())/2,n2=n1+1;
    double ans1,ans2;
    while(l<r){
        int mid = l+(r-l)/2;
        if(cal(nums1,nums2,mid)<n1) l=mid+1;
        else r = mid;
    }

    ans1 = l;

    int l2=-1e6-1,r2=1e6+1;  
    while(l2<r2){
        int mid = l2+(r2-l2)/2;
        if(cal(nums1,nums2,mid)<n2) l2=mid+1;
        else r2 = mid;
    }

    ans2 = l2;

    return (ans1+ans2)/2;  
}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l=-1e6-1,r=1e6+1,n1=nums1.size(),n2=nums2.size();
        if((n1+n2)%2==0) return solve1(nums1,nums2);
        else return solve2(nums1,nums2);
    }
};