class Solution {
    public String reverseWords(String s) {
        
        int n = 0;
        String result = "";
        int i = s.length()-1;
        while(i >= 0){
            
            while(i >= 0 && s.charAt(i) == ' ')
                i--;
            
             if(i<0) break;
            
            int j = i-1;
            
            while(j>=0 && s.charAt(j) != ' ')
                j--;  
            
            if(result.length()==0)
                result = s.substring(j+1, i+1);
            else
            result = result + " "+s.substring(j+1, i+1);   
            
            i=j-1;
            
            
        }
            return result;
    }
}