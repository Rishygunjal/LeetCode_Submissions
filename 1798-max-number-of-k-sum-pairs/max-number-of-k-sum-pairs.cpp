class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:nums){
            if((m[k-i]>0 && m[i]>0 && i!=k-i) || (m[i]>=2 && i==k-i)) {
                m[k-i]--;
                m[i]--;
                cout<<k-i<<i<<m[3]<<endl;
                ans++;
            }
        }
        return ans;
    }
};