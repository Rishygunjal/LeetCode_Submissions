class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> m;
        int ans=0;
        for(int i=arr.size()-1;i>=0;i--){
            int t =m[arr[i]],t1=1;
            int k=arr[i]+difference;
            // if(t==0){
            m[arr[i]]=1+m[arr[i]+difference];
            ans=max(m[arr[i]],ans);
            // }else{

            // }
            // while(m[k]!=0){
            //     t1++;
            //     k=k+difference;
            // }
            // m[arr[j]]=max(t,t1);
        }
        return ans;
    }
};