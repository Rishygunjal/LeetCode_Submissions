class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,pair<int,int>> hm;
        for(int i=0;i<nums.size();i++){
            cout<<hm[nums[i]].first<<endl;
            if( (hm[target-nums[i]].first!=0) && (hm[target-nums[i]].second!=i)) return vector<int>{hm[target-nums[i]].second,i};
            hm[nums[i]].first++;
            hm[nums[i]].second=i;
        }
        return {0,0};
    }
};