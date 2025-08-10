class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<string> str=strs;

        for(int i=0;i<strs.size();i++){
            sort(strs[i].begin(),strs[i].end());
        }

        vector<pair<string,int>> vec;
        for(int i=0;i<strs.size();i++){
            // pair<string,int> t(strs[i],i);
            vec.push_back({strs[i],i});
        }
        sort(vec.begin(), vec.end(), [](const pair<string,int> &a, const pair<string,int> &b) {
                return a.first < b.first;  
        });

        for(auto i:vec){
            cout<<i.first<<" vec "<<i.second<<endl;
        }

        vector<vector<string>> ans;
        for(int i=0;i<vec.size();i++){
            vector<string> t;
            string t1=vec[i].first;
            while(i<vec.size() && vec[i].first==t1){
                t.push_back(str[vec[i].second]);
                i++;
            }
            i--;
            ans.push_back(t);
        }
        return ans;
    }
};