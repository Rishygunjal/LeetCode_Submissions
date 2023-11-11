class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<vector<int>>> m;
        for(auto i:adjacentPairs){
            for(auto j:i){
                m[j].push_back(i);
            }
        }
        int start;
        for(auto i:m){
            if(i.second.size()==1) start =  i.first;
        }

        vector<int> ans{start};
        
        int prev=start,curr=m[start][0][0]==start ? m[start][0][1] : m[start][0][0];
        while(m[curr].size()!=1){
            ans.push_back(curr);
            vector<int> t;
            vector<int> c1{curr,prev},c2{prev,curr};
            if(m[curr][0] == c1 || m[curr][0] == c2) t = m[curr][1];
            else t = m[curr][0];
            int forw = t[0]==curr ? t[1] : t[0];
            prev=curr;
            curr=forw;
        }
        int end = m[curr][0][0] == curr ? m[curr][0][0] : m[curr][0][1];
        ans.push_back(end);
        return ans;  
    }
};