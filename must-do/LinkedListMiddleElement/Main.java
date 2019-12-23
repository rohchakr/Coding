/**
Definitiontion for singly-linked list.
 * public class ListNode {
 *  *     int val;
 *   *     ListNode next;
 *    *     ListNode(int x) { val = x; }
 *     * }
 *      */
class Solution {
    public ListNode middleNode(ListNode head) {
        if (head == null)
            return null;
        ListNode ptr1 = head;
        ListNode ptr2 = head;
        while(ptr2 != null && ptr2.next != null) {
            ptr1 = ptr1.next;
            ptr2 = ptr2.next.next;
        }
        return ptr1;
    }
}
