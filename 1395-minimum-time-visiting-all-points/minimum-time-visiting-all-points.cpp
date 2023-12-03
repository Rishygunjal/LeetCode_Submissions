class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0,n=points.size();
        for(int i=1;i<n;i++){
            int t= min(abs(points[i][1]-points[i-1][1]),abs(points[i][0]-points[i-1][0]));
            ans+=t + max(abs(points[i][1]-points[i-1][1]),abs(points[i][0]-points[i-1][0]))-t;;
        }
        return ans;
    }
};