class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n=pref.size();
        int t=pref[0];
        for(int i=1;i<n;i++){
            int k=pref[i];
            pref[i]=t^pref[i];
            t=k; 
        }
        return pref;
    }
};