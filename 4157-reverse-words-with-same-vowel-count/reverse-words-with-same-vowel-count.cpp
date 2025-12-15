class Solution {
public:
    string reverseWords(string s) {
        int space=int(' ');

        int l=0,r=0;
        int nov=0;
        for(;r<s.size();r++){
            if(s[r]==' ') break;
            if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') nov++;
        }

        r++;
        l=r;

        int tnov=0;
        while(r<s.size()){
            if(s[r]==' '){
                if(tnov==nov){
                    reverse(s.begin()+l,s.begin()+r);
                }
                r++;
                l=r;
                tnov=0;
            }else{
                if(s[r]=='a' || s[r]=='e' || s[r]=='i' || s[r]=='o' || s[r]=='u') tnov++;
                r++;
            }
        }
        
        if(tnov==nov){
            reverse(s.begin()+l,s.begin()+r);
        }

        return s;
    }
};