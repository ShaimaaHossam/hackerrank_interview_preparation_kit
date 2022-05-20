class Solution {
public:
    void reverseWords(vector<char>& s) {
        
        if(s.size() <= 1)
            return;
        if(!hasSpace(s))
            return ;
            
        int start = 0;
        int end = s.size()-1;
        
        reverse(s, start, end);
        
        int it = 0;
        start = it;
        end = 0;
        
        while(it <= s.size()){     
            if(s[it] == ' ' || it == s.size()){
                end = it-1;         
                reverse(s, start, end);
                start = it+1;
            }
            it++;
        }
        
        
    }
    vector<char> reverse(vector<char>& s, int start, int end){
        while(start <end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            
            start++;
            end--;
        }
        return s;
    }
    
    bool hasSpace(vector<char>& s){
        for(int i =0; i<s.size(); i++){
            if(s[i] == ' ')
                return true;
        }
        return false;
    }
    
};