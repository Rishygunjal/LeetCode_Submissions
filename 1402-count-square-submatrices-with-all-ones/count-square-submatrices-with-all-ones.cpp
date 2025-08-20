class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<pair<int,int>> ones;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    ones.push_back({i,j});
                }
            }
        }
        ans+=ones.size();
        cout<<ans<<endl;
        for(int i=2;i<=min(m,n);i++){
            for(int j=0;j<ones.size();j++){
                pair<int,int> t = ones[j];
                bool b=1;
                for(int k=t.first;k<t.first+i;k++){
                    if(k>=m) b=0;
                    if(!b) break;
                    for(int l=t.second;l<t.second+i;l++){
                        if(l>=n) b=0;
                        if(!b) break;
                        if(matrix[k][l]==0) b=0;
                        if(!b) break;
                    }
                }
                if(b) ans++;
            }
            cout<<ans<<" i "<<i<<endl;
        }
        return ans;
    }
};