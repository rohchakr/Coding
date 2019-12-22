// https://leetcode.com/problems/reverse-string/
// @rohchakr


// 0 1 2 3     0 1       < 4/2
// 0 1 2 3 4   0 1       < 5/2
class Solution {
    public void reverseString(char[] s) {
      int size = s.length;         
      for (int i = 0, j = size-1; i<size/2; i++,j--) {
        char extra_space = s[i];
        s[i] = s[j];
        s[j] = extra_space;
      }
    }
}

class Solution2 {
    public void reverseString(char[] s) {
      for (int i = 0, j = s.length-1; i<s.length/2; i++,j--) {
        s[i] = (char)(s[i] + s[j]);
        s[j] = (char)(s[i] - s[j]);
        s[i] = (char)(s[i] - s[j]);
      }   
    }   
}


class ReverseString{
  public static void main(String[] args) {
    Solution s = new Solution();
    char [] str1 = { 'h', 'e', 'l', 'l', 'o' };
    s.reverseString(str1);
    System.out.println(str1);
  }
}
