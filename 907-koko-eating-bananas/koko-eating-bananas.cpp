class Solution {

bool solve(vector<int>& piles, long long mid,int h){
    long long ctr=0;
    for(auto i: piles){
        if(i%mid==0) ctr+=(i/mid);
        else{
            ctr+=(i/mid+1);
        }
    }
    if(ctr<=h) return 1;
    else return 0;
}


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long r=0;
        for(auto i:piles){
            r = max(r,(long long)(i));
        }

        long long l=1;
        while(l<r){
            long long mid = l + (r-l)/2;
            if(!solve(piles,mid,h)){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        
        return l;
    
    }
};