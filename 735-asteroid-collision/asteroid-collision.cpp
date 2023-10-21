class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        for(auto i:asteroids){
            if(stk.empty()) stk.push(i);
            else{
                if(i>=0){
                    stk.push(i);
                }else{
                    if(stk.top()<0) stk.push(i);
                    else{
                        bool b=0;
                        while(!stk.empty()){
                            if(stk.top()>=0){
                                if(abs(stk.top())>abs(i)){
                                    break;}
                                else if(abs(stk.top())==abs(i)){
                                    stk.pop();
                                    break;
                                }else{
                                    stk.pop();
                                    if(stk.empty()){
                                        stk.push(i);
                                        break;
                                    }
                                }
                            }else{
                                stk.push(i);
                                break;
                            }
                        }
                    }
                }
            }
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};