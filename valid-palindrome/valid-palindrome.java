class Solution {
    public boolean isPalindrome(String s) {
        s = s.toLowerCase();
        
        int start=0;
        int end= s.length() - 1;
        if(s.length()==1){
            return true;
        }
        while(start<end){
            while(start < end && (!Character.isLetter(s.charAt(start)) && !Character.isDigit(s.charAt(start))))
                start ++;
            while(start < end && (!Character.isLetter(s.charAt(end)) && !Character.isDigit(s.charAt(end))))
                end --;
            
            if(s.charAt(start) != s.charAt(end)){
                return false;
            }
            
            start ++;
            end --;
        }
        return true;
    }
}