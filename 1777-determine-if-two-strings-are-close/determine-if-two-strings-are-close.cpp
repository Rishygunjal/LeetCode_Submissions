class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        if(n1!=n2) return 0;
        unordered_map<int,int> m1,m2,c1,c2;
        for(auto i:word1){
            m1[i]++;
        }
        for(auto j:word2){
            if(!m1[j]) return 0;
            m2[j]++;
        }
        for(auto j:word1){
            if(!m2[j]) return 0;
        }
        for(auto i:m1){
            c1[i.second]++;
        }
        for(auto i:m2){
            c2[i.second]++;
        }
        for(auto i:c1){
            if(c2[i.first]!=i.second) {
                return false;
            }
        }
        return 1;
    }
};