// https://leetcode.com/problems/longest-univalue-path/
// @rohchakr
// Can optimize this further by remembering the node visited

/**
 *  * Definition for a binary tree node.
 *   * public class TreeNode {
 *    *     int val;
 *     *     TreeNode left;
 *      *     TreeNode right;
 *       *     TreeNode(int x) { val = x; }
 *        * }
 *         */

class Solution {
    int maxLength;
 
    public Solution() {
      maxLength = 0;
    }   
    
    private int findLongestValuePath(TreeNode node) {
      if(node.left == null && node.right == null) {
        return 0;
      }   
      int lengthFromLeft = 0;
      int lengthFromRight = 0;
      if (node.left != null) {
        if (node.left.val == node.val) {
          lengthFromLeft = findLongestValuePath(node.left) + 1;
        } else {
          lengthFromLeft = findLongestValuePath(node.left);
          if (maxLength < lengthFromLeft) maxLength = lengthFromLeft;
          lengthFromLeft = 0;
        }
      }   
      if (node.right != null) {
        if (node.right.val == node.val) {
          lengthFromRight = findLongestValuePath(node.right) + 1;
        } else {
          lengthFromRight = findLongestValuePath(node.right);
          if (maxLength < lengthFromRight) maxLength = lengthFromRight;
          lengthFromRight = 0;
        }
      }   
      int returnValue = lengthFromLeft + lengthFromRight; 
      if (maxLength < returnValue) maxLength = returnValue;
      returnValue = (lengthFromLeft < lengthFromRight)?lengthFromRight:lengthFromLeft;
      return returnValue;
    }

    public int longestUnivaluePath(TreeNode root) {
       if (root == null) return 0; 
       int temp = findLongestValuePath(root);
       return maxLength;
    }
}

