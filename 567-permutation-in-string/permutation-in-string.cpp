class Solution {

void printUnorderedMap(const std::unordered_map<char, int>& m) {
    for (const auto& pair : m) {
        std::cout << pair.first << " => " << pair.second << " ";
    }
    cout<<endl;
}
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return 0;
        unordered_map<char,int> m1,m2;
        for(auto i:s1){
            m1[i]++;
        }
        // printUnorderedMap(m1);
        int l=0,r=0,n=s2.size();
        while(l<=r && r<n){
            m2[s2[r]]++;
            if(m2==m1) return 1;
            // printUnorderedMap(m2);
            cout<<m2[s2[l]]<<" "<<m1[s2[l]]<<endl;
            while(m2[s2[l]]>m1[s2[l]] && l<=r){
                m2[s2[l]]--;
                l++;
            }

            if(m2==m1) return 1;
            r++;
        }
        return 0;
    }
};