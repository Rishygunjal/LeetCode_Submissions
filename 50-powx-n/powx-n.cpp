class Solution {
public:
    double myPow(double x, int n) {
        // if(n==-INT_MAX  ) return 0;
        if(x==0) return 0;
        if(n==0) return 1;
        if(n==1) return double(x);
        if(n==2) return double(x*x);
        if(n==-1) return double(1/x);
        if(n==-2) return double(1/x)*double(1/x);

        int mid = n/2;
        double t = myPow(x,mid);
        if(abs(n)%2==0){
            return t*t;
        }else{
            double k = (n>0) ? x : 1/x;
            return t*t*k;
        }
    }
};