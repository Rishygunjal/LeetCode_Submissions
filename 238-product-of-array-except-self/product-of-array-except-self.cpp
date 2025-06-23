class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> noOfZeroes,ans;
        int product=1;
        for(int i=0;i<nums.size();i++){
            product*=nums[i];
            if(nums[i]==0) noOfZeroes.push_back(i);
        }
        // cout<<noOfZeroes.size()<<endl;
        if(product==0){
            if(noOfZeroes.size()>1){
                return vector<int> (nums.size(),0);
            }else{
                product=1;
                for(int i=0;i<nums.size();i++){
                    if (i==noOfZeroes[0]) continue;
                    product*=nums[i];
                }
                for(int i=0;i<nums.size();i++){
                    if(i==noOfZeroes[0]) {
                        ans.push_back(product);
                        continue;
                    }
                    ans.push_back(0);
                }
                return ans;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(product/nums[i]);
        }
        return ans;
    }
};