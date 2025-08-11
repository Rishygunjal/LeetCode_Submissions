class Solution {

bool checkPalindrome(string s){
    int i=0,j=s.size()-1;
    while(i<=j){
        // cout<<s[i]<<" "<<s[j]<<endl;
        if(s[i]!=s[j]) return 0;
        i++;j--;
    }
    return 1;
}

public:
    bool isPalindrome(string s) {
        string st;
        for(auto i:s){
            if(isalnum(i)) {
                if(i>=65 and i<=90){
                    i+=32;
                    // cout<<i<<"big"<<endl;
                    st+=i;
                }
                else{
                    st+=i;
                }
            }
        }
        cout<<st<<endl;
        return checkPalindrome(st);
    }
};