class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        if(1){
            for(int i=0;i<n;i++){
                int l=0,r=m-1;
                if(grid[i][r]>=0) continue;
                while(l<r){
                    int mid = l+(r-l)/2;
                    if(grid[i][mid]>=0){
                        l=mid+1;
                    }else{
                        r=mid;
                    }
                }
                ans+=(m-r); 
            }
            return ans;
        }
        return -1;
    }
};