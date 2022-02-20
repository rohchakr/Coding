import java.util.*;

/**
 * https://leetcode.com/problems/remove-covered-intervals
 * @rohchakr
 */

class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        // O(nlogn)
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] < b[0])
                return -1;
            if (a[0] > b[0])
                return 1;
            if (a[1] < b[1])
                return -1;
            if (a[1] > b[1])
                return 1;
            return 0;
        });
        
        int size = intervals.length;
        int intervalCount = size;
        int[] prev = {intervals[0][0], intervals[0][1]};
        for (int i = 1; i < size; i++) {
            if (intervals[i][0] > prev[0]) {
                if (intervals[i][1] <= prev[1]) {
                    intervalCount--;
                } else {
                    prev[0] = intervals[i][0];
                    prev[1] = intervals[i][1];
                }
            } else if (intervals[i][0] == prev[0]) {
                intervalCount--;
                prev[1] = Math.max(prev[1], intervals[i][1]);
            } else {
                // sorting error
            }
        }

        return intervalCount;
    }

    public static void main (String[] args) {
        int[][] intervals = {{1,2},{1,4},{3,4}};
        System.out.println(new Solution().removeCoveredIntervals(intervals));
    }
}