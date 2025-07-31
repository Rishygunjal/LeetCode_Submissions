class Solution {

int solve(string s, int i, vector<int>& dp){
    if(i>=s.size()) return 0;

    if(dp[i]!=-1) return dp[i];

    if(i==s.size()-1){
        cout<<"n-1   "<<s[i]<<endl;
        if(s[i]=='0'){
            return dp[i]=0;
        }
        return dp[i]=1;
    }
    else if(i==s.size()-2){
        string s1 = s.substr(i,2);
        string s2 = s.substr(i,1);
        cout<<s1<<" "<<s2<<endl;
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        cout<<n1<<" n1 "<<n2<<" n2 "<<endl;
        if(s[i]=='0') return 0;
        else if(n1>0 && n1<=26){
            if(s[i+1]=='0') return dp[i]=1;
            return dp[i]=2;
        }
        else return dp[i]=solve(s,i+1,dp);
    }else{
        string s1 = s.substr(i,2);
        string s2 = s.substr(i,1);
        cout<<s1<<" "<<s2<<endl;
        int n1 = stoi(s1);
        int n2 = stoi(s2);
        cout<<n1<<" zzzn1 "<<n2<<" n2 "<<endl;
        int ans=0;
        if(s[i]=='0') return dp[i]=0;
        else if(n1>0 && n1<=26){
            int ans1 = solve(s,i+2,dp);
            int ans2 = solve(s,i+1,dp); 
            ans=ans1+ans2;
        }
        else{
            int ans1 = solve(s,i+1,dp);
            ans=ans1;
        }
        return dp[i]=ans;
    }
}

public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s,0,dp);
    }
};