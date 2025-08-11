class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]=1;
        }
        int ans=0;
        for(auto i:nums){
            if(mp[i]==2) continue;
            int t=1;
            mp[i]=2;
            int mid1=i-1,mid2=i+1;
            while(mp[mid1]==1){
                t++;
                mp[mid1]=2;
                mid1--;
            }
            while(mp[mid2]==1){
                t++;
                mp[mid2]=2;
                mid2++;
            }
            ans=max(ans,t);
        }
        return ans;
    }
};

