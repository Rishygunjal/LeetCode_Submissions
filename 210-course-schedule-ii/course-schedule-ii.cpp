class Solution {


private:
	void topo(unordered_map<int,vector<int>>& adj, vector<bool>& visited, stack<int>& s, int i){
        visited[i]=1;
        for(auto neighbour:adj[i]){
            if(!visited[neighbour]){
                topo(adj,visited,s,neighbour);
            }
        }
        s.push(i);
        return;
}


public:
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	    unordered_map<int,vector<int>> adj;
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        stack<int> s;
        vector<bool> visited(numCourses+1,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                topo(adj,visited,s,i);
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        unordered_map<int,int> mp;
        for(int i=0;i<ans.size();i++){
            mp[ans[i]]=i;
        }

        for(auto i:prerequisites){
            if(mp[i[1]]>mp[i[0]]){
                return {};
            }
        }

        return ans;
   }
};

