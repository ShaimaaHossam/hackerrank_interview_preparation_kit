class Solution {
 public int myAtoi(String s) {
   if(s == null || s.length()==0)
       return 0;

   String actual = "";
   long num = 0;
   long sign = 1;
   for(int i = 0 ; i < s.length() ; i++){
       if(s.charAt(i)!=' '){
           if( actual.length() == 0 && i+1 < s.length()
              && (s.charAt(i) == '-' || s.charAt(i) == '+') 
              && Character.isDigit(s.charAt(i+1)))
               actual += s.charAt(i);

           else if(!Character.isDigit(s.charAt(i)))
               break;
           else if(Character.isDigit(s.charAt(i)))
               actual += s.charAt(i);

           if(i+1 < s.length() && s.charAt(i+1)==' ')
               break;

       }
   }

  if(actual.length() == 0)
      return 0;
  if(actual.charAt(0) == '-')
      sign = -1;

  for(int i=0; i<actual.length(); i++){
      if(Character.isDigit(actual.charAt(i))){
          num = num*10 + (actual.charAt(i) - '0');
          if(num*sign >= Integer.MAX_VALUE)
              return Integer.MAX_VALUE;
          else if( num*sign <= Integer.MIN_VALUE)
              return Integer.MIN_VALUE;
      }
  }

 return (int) (num*sign);
}
}