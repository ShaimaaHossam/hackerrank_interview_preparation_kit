class Solution {
public:
    bool isValid(string s) {
        if(s.length() <= 1){
            return false;
        }
        stack<char> stck;
        
        
        for(int i=0 ; i<s.length(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] =='['){
                stck.push(s[i]);
            }
            else if(s[i] == '}' || s[i] == ')' || s[i] ==']'){
                if(stck.empty())
                    return false;
                
                char tmp = stck.top();
                if(tmp == '{' &&( s[i] == ')' || s[i] == ']'))
                    return false;
                if(tmp == '[' &&( s[i] == ')' || s[i] == '}'))
                    return false;
                if(tmp == '(' &&( s[i] == '}' || s[i] == ']'))
                    return false;
                
                stck.pop();
            }
        }
        if(stck.empty())
            return true;
        else
            return false;
        
    }
};
