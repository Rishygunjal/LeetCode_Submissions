class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),l=0,r=n-1;

        while(l<r){
            int mid = l+ (r-l+1)/2;
            if(matrix[mid][0]>target){
                r = mid-1;
            }else{
                l = mid;
            }
        }
        if(matrix[r][0]==target) return 1;
        int row = l;
        // cout<<row<<endl;

        l=0,r=m-1;
        while(l<r){
            int mid = l+(r-l)/2;
            if(matrix[row][mid]<target) l = mid+1;
            else r = mid;
        }

        if(matrix[row][r]==target) return 1;
        else return 0;
    }
};