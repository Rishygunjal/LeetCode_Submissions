class Solution {
public:
    bool isValid(string str) {
        stack<char> s;
        for(auto i:str){
            if(i=='(' || i=='{' || i=='['){
                s.push(i);
            }else{
                if(s.empty()) return 0;
                if(i==')'){
                    if(s.top()=='('){
                        s.pop();
                    }else{
                        return 0;
                    }
                }
                else if(i=='}'){
                    if(s.top()=='{'){
                        s.pop();
                    }else{
                        return 0;
                    }
                }
                else if(i==']'){
                    if(s.top()=='['){
                        s.pop();
                    }else{
                        return 0;
                    }
                }
            }
        }
        return s.empty();
    }
};