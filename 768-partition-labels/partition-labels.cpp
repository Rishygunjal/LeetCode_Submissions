class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m1,m2;
        for(auto i:s){
            m1[i]++;
            m2[i]++;
        } 

        int i=0,n=s.size(),t=0,et=0;
        vector<int> ans;
        while(i<n){
            m1[s[i]]--;
            t++;
            if(m1[s[i]]==0){
                m1.erase(s[i]);
                et+=m2[s[i]];
                if(t==et) {
                    ans.push_back(t);
                    t=0,et=0;
                }
            }
            i++;
        }
        return ans;
    }
};