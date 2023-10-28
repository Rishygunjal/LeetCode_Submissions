class Solution {

int solve(vector<int>& values, int i, bool b){
    if(i==values.size()) return INT_MIN+1e4;

    if(!b){
        int p = values[i] + i + solve(values,i+1,1);
        int np = solve(values,i+1,0);
        return max(p,np);
    }else{
        int p = values[i]-i;
        int np = solve(values,i+1,1);
        return max(p,np);
    }
}

int solveMem(vector<int>& values, int i, bool b, vector<vector<int>>& dp){
    if(i==values.size()) return INT_MIN+1e4;
    

    if(!b){
        if(dp[i][0]!=-1) return dp[i][0];
        int p = values[i] + i + solve(values,i+1,1);
        int np = solve(values,i+1,0);
        return dp[i][0]=max(p,np);
    }else{
        if(dp[i][1]!=-1) return dp[i][1];
        int p = values[i]-i;
        int np = solve(values,i+1,1);
        return dp[i][1]=max(p,np);
    }
}

int solveTab(vector<int>& values){
    vector<vector<int>> dp(values.size()+1,vector<int> (2,INT_MIN+1e4));
    // if(i==values.size()) return INT_MIN+1e4;
    int n=values.size();

    for(int i=n-1;i>=0;i--){
        for(int b=1;b>=0;b--){
            if(b==0){
                int p = values[i] + i + dp[i+1][1];
                int np = dp[i+1][0];
                dp[i][0]=max(p,np);
            }else{
                int p = values[i]-i;
                int np = dp[i+1][1];
                dp[i][1]=max(p,np);
            }
        }
    }

    return dp[0][0];
    
}

public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // return solve(values,0,0);
        // vector<vector<int>> dp(values.size()+1,vector<int> (2,-1));
        // return solveMem(values,0,0,dp);
        return solveTab(values);
    }
};