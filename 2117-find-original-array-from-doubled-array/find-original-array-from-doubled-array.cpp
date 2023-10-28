class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int> m;
        int n=changed.size();
        if(n%2!=0) return {};

        for(auto i:changed){
            m[i]++;
        }
        vector<int> ans;
        sort(changed.begin(),changed.end());
        for(auto i:changed){
            if(m[i]){
                if(m[i*2]>0){
                    ans.push_back(i);
                    m[i*2]--;
                    m[i]--;
                }else{
                    return {};
                }
            }
        }
        return ans;
    }
};