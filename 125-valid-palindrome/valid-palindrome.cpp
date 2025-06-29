class Solution {
public:
    bool isPalindrome(string s) {
        string news;
        for(auto i:s){
            if(isalnum(i)){
                news.push_back(tolower(i));
            }
        }
        int i=0,j=news.size()-1;
        while(i<=j){
            if(news[i]!=news[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
};