class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n =arr.size();
        if(n==1) return 1;
        arr[0]=1;
        int prev = 1;
        for(int i=1;i<n;i++){
            // if(i>207) cout<<arr[i]<<arr[i-1]<<endl;
            while(i<n && abs(arr[i]-arr[i-1])<=1){
                // cout<<i<<" "<<arr[i]<<endl;
                i++;
                prev=arr[i-1];
            }
            if(i==n) break;
            // if(i>207) cout<<i<<"here"<<arr[i]<<endl;
            arr[i]=prev+1;
            prev++;
        }
        // cout<<arr[n-3]<<" "<<arr[n-2]<<" "<<arr[n-1]<<endl;
        return arr[n-1];
    }
};