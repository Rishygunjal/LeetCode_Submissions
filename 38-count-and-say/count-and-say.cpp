class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        string ans="";
        int n1=s.size();
        for(int i=0;i<n1;i++){
            char t = s[i];
            int ctr=0;
            while(s[i]==t){
                ctr++;
                i++;
            }
            cout<<ctr<<t<<char(ctr) +t<<endl;
            ans+=to_string(ctr);
            ans += t;
            i--;
        }
        return ans;
    }
};