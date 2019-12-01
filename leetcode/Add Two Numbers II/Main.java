// https://leetcode.com/problems/add-two-numbers-ii/
// @rohchakr


/**
 *  * Definition for singly-linked list.
 *   * public class ListNode {
 *    *     int val;
 *     *     ListNode next;
 *      *     ListNode(int x) { val = x; }
 *       * }
 *        */
class Solution {
    
    int maxL1L2size;
    int carry;

    private int size (ListNode l1) {
      ListNode n = l1;
      int length = 1;
      while (n.next != null) {
        n = n.next;
        length++;
      }
      return length;
    }

    private ListNode getSum(ListNode l1, ListNode l2, int index1, int index2) {

      ListNode listNode;  
      if(index1 == maxL1L2size - 1) {
        int sum = l1.val + l2.val;
        carry = sum / 10;
        sum = sum % 10;
        listNode = new ListNode(sum);
      } else {
        int val1 = l1.val;
        int val2;
        
        listNode = new ListNode(0);
        if (index1 < index2) {
          listNode.next = getSum(l1.next, l2, index1+1, index2);
          val2 = 0;  
        } else {
          listNode.next = getSum(l1.next, l2.next, index1+1, index2+1);
          val2 = l2.val;  
        }
        carry += listNode.next.val / 10;
        listNode.next.val %= 10;
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        listNode.val = sum; 
          
      }
      if (index1 == 0) {
          while(carry != 0) {
            ListNode newListNode = new ListNode(carry%10);
            newListNode.next = listNode;
            listNode = newListNode;
            carry = carry/10;
          }
      }
      return listNode;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      if (size(l1) < size(l2)) {
        ListNode l3 = l1;
        l1 = l2;
        l2 = l3;
      }
      int index1 = 0;
      int index2 = size(l1) - size(l2);
      maxL1L2size = size(l1);
      carry = 0;
      ListNode ans = getSum(l1,l2,index1,index2);
      return ans;

    }
}
