class Solution {
public:
    string removeStars(string s) {
        //O(n),O{n}
        int toremove=0,i=s.size()-1;
        string ans;
        while(i>=0){
            if(s[i]=='*') toremove++;
            else{
                if(toremove>0) {toremove--;i--;continue;}
                else ans+=s[i];
            }
            i--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};