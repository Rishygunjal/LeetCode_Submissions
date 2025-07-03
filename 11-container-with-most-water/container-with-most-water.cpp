class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0,i=0,j=height.size()-1;
        while(i<j){
            cout<<"ans "<<i<<" "<<j<<" nums "<<min(height[i],height[j])*(j-i)<<endl;
            ans=max(ans,min(height[i],height[j])*(j-i));
            if(height[i]<height[j]){
                int t=height[i];
                while(height[i]<=t && i<j){
                    i++;
                }
            }else{
                int t=height[j];
                while(height[j]<=t && i<j){
                    
                    cout<<height[j]<<" "<<t<<endl;
                    j--;

                }
            }
        }
        return ans;
    }
};