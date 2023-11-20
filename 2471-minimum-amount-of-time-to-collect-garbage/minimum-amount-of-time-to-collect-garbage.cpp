class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int> metal,glass,paper;
        for(int i=0;i<n;i++){
            for(auto j:garbage[i]){
                if(j=='M' && (metal.size()==0 || metal[metal.size()-1]!=i)) metal.push_back(i);
                if(j=='G' && (glass.size()==0 || glass[glass.size()-1]!=i)) glass.push_back(i);
                if(j=='P' && (paper.size()==0 || paper[paper.size()-1]!=i)) paper.push_back(i);
            }
        }
        int mt=0,gt=0,pt=0;
        int j=0;
        if(metal.size()!=0){
            for(int i=0;i<n;i++){
                if(metal[j]==i){
                    for(auto k:garbage[i]){
                        mt+=k=='M';
                    }
                    j++;
                }
                if(j==metal.size()) break;
                mt+=travel[i];
            }
        }
        j=0;
        if(paper.size()!=0){
            for(int i=0;i<n;i++){
                if(paper[j]==i){
                    for(auto k:garbage[i]){
                        mt+=k=='P';
                    }
                    j++;
                }
                if(j==paper.size()) break;
                mt+=travel[i];
            }
        }
        j=0;
        if(glass.size()!=0){
            for(int i=0;i<n;i++){
                if(glass[j]==i){
                    for(auto k:garbage[i]){
                        mt+=k=='G';
                    }
                    j++;
                }
                if(j==glass.size()) break;
                mt+=travel[i];
            }
        }
        return gt+mt+pt;
    }
};