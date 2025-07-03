class Solution {
    // 0 3 5 8 10
    // 12 9 7 4 2
    // 1 3 1 4 2
    // 12 3 7 1 1 
    // 1 1 7 3 12


    // 7 8 11 12 16
    // 10 9 6 5 1
    // 7 6 9 9 10
    // 1.4 1.5 0.67 0.55 0.1
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==1) return 1;
        unordered_map<int,int> mp;
        for(int i=0;i<position.size();i++){
            mp[position[i]]=i;
        }
        sort(position.begin(),position.end());
        // reverse(position.begin(),position.end());
        vector<int> newspeed;
        for(int i=0;i<speed.size();i++){
            newspeed.push_back(speed[mp[position[i]]]);
        }
        stack<float> time;
        for(int i=0;i<speed.size();i++){
            // cout<<float(12-position[i])/float(newspeed[i])<<float(newspeed[i])<<endl;
            time.push(float(target-position[i])/float(newspeed[i]));
        }
        int ans=1;
        float t=time.top();
        time.pop();
        bool b=0;
        while(!time.empty()){
            if(time.top()<=t){
                time.pop();
                b=0;
            }else{
                cout<<time.top()<<" "<<t<<" "<<ans<<endl;
                ans++;
                t=time.top();
                time.pop();
                // if(time.empty()) return ans-1;
                b=1;
            }
        }
        // if(!b) return ans;
        return ans;
    }
};