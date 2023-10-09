class Solution {

    bool check(int mid,vector<int>& weights, int days){
        int ctr=0,i=0,n=weights.size(),t=0;
        while(i<n){
            // cout<<t<<weights[i]<<" startwhile"<<endl;
            if(weights[i]>mid)
                return false;
            
            if(t+weights[i]<=mid){
                t+=weights[i];
                i++;
            }else{
               
                t=0;
                ctr++;
                // cout<<"cap "<<i<<ctr<<" "<<t<<mid<<endl;
                if(ctr>days) return 0;
            }
        }
        // cout<<"final t"<<t<<endl;/
        if(t>0) ctr++;
        if(ctr>days) return 0;
        else return 1;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(auto i:weights){
            sum+=i;
        }
        int n = weights.size();
        int l = 1,r = sum;
        while(l<r){
            int mid = l + (r-l)/2;
            // bool t = check(mid,weights,days);
            // cout<<t<<mid<<endl;
            if(!check(mid,weights,days)) l = mid+1;
            else r = mid; 
        }

        return l;
    }
};