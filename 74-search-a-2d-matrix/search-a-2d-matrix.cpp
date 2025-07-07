class Solution {

bool condition1(vector<vector<int>>& matrix, int target, int mid){
    return matrix[mid][0]>target;
}

bool condition2(vector<vector<int>>& matrix, int target, int mid, int v1){
    return matrix[v1][mid]>=target;
}

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix[0][0]>target || matrix[matrix.size()-1][matrix[0].size()-1]<target) return 0;
        int lo=-1,hi=matrix.size();
        while(lo+1<hi){
            int mid = lo + floor((hi-lo)/2);
            cout<<hi<<" "<<lo<<" "<<mid<<endl;
            if(condition1(matrix,target,mid)){
                hi=mid;
            }
            else{
                lo=mid;
            }
        }
        int v1 = hi-1;

        cout<<"v1 "<<v1<<endl;

        if(v1==-1) return 0;

        if(matrix[v1][matrix[0].size()-1]<target || matrix[v1][0]>target) return 0;

        lo=-1,hi=matrix[0].size();
        while(lo+1<hi){
            int mid = lo + floor((hi-lo)/2);
            if(condition2(matrix,target,mid,v1)){
                hi=mid;
            }else{
                lo=mid;
            }
        }

        if(matrix[v1][hi]==target) return 1;
        else return 0;
    }
};