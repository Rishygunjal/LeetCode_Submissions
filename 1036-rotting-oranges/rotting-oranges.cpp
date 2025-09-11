class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int ans=-1;
        // int k=q.size();
        // cout<<q.size();

        // while(k>0){
        //     k--;
        //     pair<int,int> t = q.front();
        //     grid[t.first][t.second]=2;
        //     q.pop();
        //     if(t.first-1>=0){
        //         if(grid[t.first-1][t.second]==1) q.push({t.first-1,t.second});
        //     }
        //     if (t.first+1<grid.size() && grid[t.first+1][t.second]==1) q.push({t.first+1,t.second});
        //     if (t.second-1>=0 && grid[t.first][t.second-1]==1) q.push({t.first,t.second-1});
        //     if (t.second+1<grid[0].size() && grid[t.first][t.second+1]==1) q.push({t.first,t.second+1});
        // }

        if(fresh==0) return 0;
        if(q.size()==0) return -1;


        cout<<q.size()<<endl;

        while(q.size()!=0){
            int k=q.size();

            while(k>0){
                k--;
                pair<int,int> t = q.front();
                // grid[t.first][t.second]=2;
                cout<<t.first<<t.second<<endl;
                q.pop();
                if(t.first-1>=0){
                    if(grid[t.first-1][t.second]==1) {
                        q.push({t.first-1,t.second});
                        grid[t.first-1][t.second]=2;
                    }
                }
                if (t.first+1<grid.size() && grid[t.first+1][t.second]==1) {
                    q.push({t.first+1,t.second});
                    grid[t.first+1][t.second]=2;
                }
                if (t.second-1>=0 && grid[t.first][t.second-1]==1) {
                    q.push({t.first,t.second-1});
                    grid[t.first][t.second-1]=2;
                }
                if (t.second+1<grid[0].size() && grid[t.first][t.second+1]==1) {
                    q.push({t.first,t.second+1});
                    grid[t.first][t.second+1]=2;
                }
            }
            cout<<q.size()<<endl;
            if(q.size()!=0) cout<<q.front().first<<q.front().second<<endl;
            
            ans++;
        }

        for(auto i:grid){
            for(auto j:i){
                if(j==1) return -1;
            }
        }

        return ans;
    }
};