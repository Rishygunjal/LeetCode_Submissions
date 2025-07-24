class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int> v1,v2;
        v1.push_back(cardPoints[0]);
        v2.push_back(cardPoints[n-1]);
        for(int i=1;i<k;i++){
            v1.push_back(cardPoints[i]+v1[i-1]);
            v2.push_back(cardPoints[cardPoints.size()-1-i]+v2[v2.size()-1]);
        }


        int ans=0;
        ans=max(ans,v1[k-1]);
        ans=max(ans,v2[k-1]);
        cout<<v1[k-1]<<" "<<v2[k-1]<<v1.size()<<v2.size()<<endl;
        for(int i=1;i<k;i++){
            int t=0;
            t+=v1[i-1];
            t+=v2[k-i-1];
            cout<<v1[i-1]<<" "<<v2[k-i-1]<<endl;
            ans=max(ans,t);
        }
        return ans;
    }
};