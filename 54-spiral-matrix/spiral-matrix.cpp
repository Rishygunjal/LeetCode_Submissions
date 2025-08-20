class Solution {

void traverseright(vector<int>& ans, vector<vector<int>>& matrix, int up, int down, int left, int right){
    for(int i=left;i<=right;i++){
        ans.push_back(matrix[up][i]);
    }
}

void traversedown(vector<int>& ans, vector<vector<int>>& matrix, int up, int down, int left, int right){
    for(int i=up;i<=down;i++){
        ans.push_back(matrix[i][right]);
    }
}

void traverseleft(vector<int>& ans, vector<vector<int>>& matrix, int up, int down, int left, int right){
    for(int i=right;i>=left;i--){
        ans.push_back(matrix[down][i]);
    }
}

void traverseup(vector<int>& ans, vector<vector<int>>& matrix, int up, int down, int left, int right){
    for(int i=down;i>=up;i--){
        ans.push_back(matrix[i][left]);
    }
}

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int up=0,left=0,down=matrix.size()-1,right=matrix[0].size()-1;
        int dir=0;
        while(up<=down && left<=right){
            if(dir==0){
                cout<<"running?";
                traverseright(ans,matrix,up,down,left,right);
                dir=1;
                up++;
                cout<<up<<down<<left<<right<<endl;;

            }else if(dir==1){
                traversedown(ans,matrix,up,down,left,right);
                dir=2;
                right--;
                cout<<up<<down<<left<<right<<endl;;
            }else if(dir==2){
                traverseleft(ans,matrix,up,down,left,right);
                dir=3;
                down--;
                cout<<up<<down<<left<<right<<endl;;
    
            }else{
                traverseup(ans,matrix,up,down,left,right);
                dir=0;
                left++;
                cout<<up<<down<<left<<right<<endl;;
            }
        }
        // if(ans[ans.size()-1]!=matrix[up][left]){
        //     ans.push_back(matrix[up][left]);
        // }
        return ans;
    }
};