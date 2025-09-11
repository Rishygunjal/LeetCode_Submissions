class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int i=0;
        // vectot<int> ans;
        // while(asteroids[i]<0){
        //     ans.push_back(asteroids[i]);
        //     i++;
        // }

        while(i<asteroids.size()){
            int t = asteroids[i];
            if(t>0){
                stk.push(t);
            }else{
                if(stk.empty()){
                    stk.push(t);
                }
                else{
                    int k = stk.top();
                    if(k<0){
                        stk.push(t);
                    }else{
                        if(abs(t)<abs(k)){
                        }else if(abs(k)==abs(t)){
                            stk.pop();
                        }else{
                            while(stk.size()!=0 && stk.top()>0 && (abs(stk.top()) < abs(t)) ){
                                stk.pop();
                            }
                            if(stk.empty()){
                                stk.push(t);
                            }else if(stk.top()<0){
                                stk.push(t);
                            }else if(  abs(stk.top()) == abs(t)  ) {
                                stk.pop();
                            }else if( abs(stk.top()) > abs(t) ){

                            }
                        }
                    }
                }
            }
            i++;
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