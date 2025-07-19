class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,n=s.size(),ans=0,t=0;

        while(l<=r && r<n){
            mp[s[r]]++;
            t++;
            if(mp[s[r]] > 1){
                while(l<=r){
                    mp[s[l]]--;
                    l++;
                    t--;
                    if(mp[s[r]]==1) break;
                }
                ans=max(ans,t);
            }else{
                ans=max(ans,t);
            }
            cout<<t<<" "<<r<<" "<<l<<endl;
            r++;
        }
        return ans;
        
    }
};