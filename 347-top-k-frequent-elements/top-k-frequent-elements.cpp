class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> hm1;
        for(auto i:nums){
            hm1[i]++;
        }

        map<int,vector<int>> m1;
        for(auto i:hm1){
            m1[i.second].push_back(i.first);
        }
        vector<int> ans;
        while(k>0){
            for(auto it = m1.rbegin(); it != m1.rend(); ++it){  
                for (int val : it->second) {
                    ans.push_back(val);
                    k--;
                    if(k==0) break;
                }
                if(k==0) break;
            }
        }
        return ans;
    }
};