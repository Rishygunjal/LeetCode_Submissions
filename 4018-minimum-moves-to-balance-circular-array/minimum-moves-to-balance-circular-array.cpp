class Solution {
public:
    long long minMoves(vector<int>& balance) {
        long long nindex=-1,sum=0;
        for(long long i=0;i<balance.size();i++){
            if(balance[i]<0) nindex=i;
            sum+=balance[i];
        }
        if(sum<0) return -1;
        if(nindex==-1) return 0;

        long long nvalue=balance[nindex];

        // long long l=nindex,r=nindex;

        long long limit = balance.size()/2;

        long long ans=0;
        nvalue=abs(nvalue);

        cout<<nindex<<" "<<nvalue<<endl;

        for(long long i=1;i<=limit;i++){
            long long lindex = nindex-i;
            if(lindex<0){
                lindex = balance.size()+lindex;
            }

            long long rindex = nindex+i;
            if(rindex>=balance.size()){
                rindex = rindex-balance.size();
            }
            cout<<lindex<<" "<<rindex<<endl;


            long long t = balance[lindex]+balance[rindex];
            if(t>=nvalue){
                ans+=nvalue*i;
                break;
            }else{
                ans+=t*i;
                nvalue-=t;
            }
        }
        return ans;
    }
};