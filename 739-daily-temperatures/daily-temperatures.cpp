class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        vector<int> ans,t=temperatures;
        int n=t.size();
        st.push({t[n-1],n-1});
        ans.push_back(0);

    for(int i=n-2;i>=0;i--){
        if(t[i]<t[i+1]){
            ans.push_back(1);
            st.push({t[i],i});
        }else{
            while(!st.empty() && t[i]>=st.top().first){
                st.pop();
            }
            if(st.empty()){
                ans.push_back(0);
                st.push({t[i],i});
            }
            else{
                ans.push_back(st.top().second-i);
                st.push({t[i],i});
            }
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};