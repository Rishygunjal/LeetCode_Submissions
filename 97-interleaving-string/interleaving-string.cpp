class Solution {

bool solve(string s1,string s2, string s3, int i, int j,int k){
    if(k==s3.size()){
        return 1;
    }else if(i==s1.size()){
        for(int x=j;x<s2.size();x++,k++){
            if(s2[x]!=s3[k]) return 0;
        }
        return 1;
    }else if(j==s2.size()){
        for(int x=i;x<s1.size();x++,k++){
            if(s1[x]!=s3[k]) return 0;
        }
        return 1;
    }
    char t=s3[k],t1=s1[i],t2=s2[j];
    if(t==t1 && t==t2){
        return solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1);
    }else if(t==t1){
        return solve(s1,s2,s3,i+1,j,k+1);
    }else if(t==t2) return solve(s1,s2,s3,i,j+1,k+1);
    else return 0;
}

bool solveMem(string s1,string s2, string s3, int i, int j,int k,vector<vector<int>>& dp){
    if(k==s3.size()){
        return 1;
    }else if(i==s1.size()){
        for(int x=j;x<s2.size();x++,k++){
            if(s2[x]!=s3[k]) return 0;
        }
        return 1;
    }else if(j==s2.size()){
        for(int x=i;x<s1.size();x++,k++){
            if(s1[x]!=s3[k]) return 0;
        }
        return 1;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    char t=s3[k],t1=s1[i],t2=s2[j];
    if(t==t1 && t==t2){
        return dp[i][j]=(solveMem(s1,s2,s3,i+1,j,k+1,dp) || solveMem(s1,s2,s3,i,j+1,k+1,dp));
    }else if(t==t1){
        return dp[i][j]=solveMem(s1,s2,s3,i+1,j,k+1,dp);
    }else if(t==t2) return dp[i][j]=solveMem(s1,s2,s3,i,j+1,k+1,dp);
    else return 0;
}

public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return 0;
        // return solve(s1,s2,s3,0,0,0);
        vector<vector<int>> dp(s1.size()+1,vector<int> (s2.size()+1,-1));
        return solveMem(s1,s2,s3,0,0,0,dp);
    }
};