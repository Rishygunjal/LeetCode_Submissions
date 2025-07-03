class Solution {

void solve(vector<string> &ans, int open, int closed, string t){
    if(open>closed || open<0 || closed<0) return;
    if(open==0 && closed==0) {
        ans.push_back(t);
        return;
    }
    
    solve(ans,open-1,closed,t+"(");
    solve(ans,open,closed-1,t+")");
}

public:
    vector<string> generateParenthesis(int n) {
        int open=n,closed=n;
        vector<string> ans;
        solve(ans,open,closed,"");
        return ans;
    }
};