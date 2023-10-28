class Solution {

static bool compare(const pair<int,int> &a,const pair<int,int> &b){
    return a.first<b.first;
}

bool check(int i,string t,string s){
    string k = s.substr(i,t.size());
    if(k==t) return 1;
    else return 0;
}

public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans="";
        int n =s.size();
        vector<bool> b;
        vector<pair<int,int>> pos;
        for(int i=0;i<indices.size();i++){
            pos.push_back({indices[i],i});
            if(check(indices[i],sources[i],s)){
                b.push_back(1);
            }else b.push_back(0);
        }
        int prev=0;
        sort(pos.begin(),pos.end(),compare);

        for(int i=0;i<pos.size();i++){
            if(b[pos[i].second]==1){
                string t=s.substr(prev,indices[pos[i].second]-prev);
                ans+=t;
                ans+=targets[pos[i].second];
                prev = indices[pos[i].second]+sources[pos[i].second].size();
            }
        }
        if(prev!=n){
            string t=s.substr(prev,n-prev);
            ans+=t;
        }
        return ans;
    }
};