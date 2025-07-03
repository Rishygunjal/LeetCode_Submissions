class Solution {

char next(char c){
    if(c=='z') return 'a';
    return c+1;
}

public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string s2;
            for(auto i:s){
                s2+=next(i);
            }
            s+=s2;
        }
        return s[k-1];
    }
};