class Solution {

bool condition(int mid, vector<int> piles, int h){
    // cout<<"mid"<<mid<<endl;
    // vector<int> piles1=piles
    long long noh=0,i=0,n=piles.size();
    // while(i<n){
    //     while(piles[i]>0){
    //         piles[i]-=mid;
    //         noh++;
    //         // cout<<noh<<"noh"<<endl;
    //         if(noh>h) return 0;
    //     }
    //     i++;
    // }
    // if(noh>h) return 0;
    // return 1;


    for (int p : piles)
        noh += (p + mid - 1) / mid;
        if(noh>h) return 0;
    if(noh>h) return 0;
    return 1;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int hi=0,lo=0;
        for(auto i:piles){
            hi=max(hi,i);
        }
        hi++;

        while(lo+1<hi){
            int mid=lo+floor((hi-lo)/2);
            // cout<<lo<<" "<<mid<<" "<<hi<<endl;
            if(condition(mid,piles,h)){
                hi=mid;
            }else{
                lo=mid;
            }
        }

        return hi;
    }
};