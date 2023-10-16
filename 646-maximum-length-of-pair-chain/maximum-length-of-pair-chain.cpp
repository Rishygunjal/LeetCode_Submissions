class Solution {

static bool sortbyCond(const vector<int>& a,
                const vector<int>& b)
{
    // if (a[0] != b[0])
    //     return (a[0] < b[0]);
    // else
    //    return (a[1] < b[1]);
    return a[1]<b[1];
}

int solve(vector<vector<int>>& pairs, int i){
    if(i==pairs.size()){
        return 0;
    }
    vector<int> t=pairs[i];
    i++;
    while(i<pairs.size()){
        if(t[1]<pairs[i][0]){
            return 1+solve(pairs,i);
        }
        i++;
    }
    return 1;
}

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),sortbyCond);
        return solve(pairs,0);
    }
};