import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int x = s.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = s.nextInt();
        }

        int INFINITY = x + 1;

        int[] dp = new int[x + 1];
        for (int i = 1; i <= x; i++)
            dp[i] = INFINITY;
        // base case
        // dp[0] = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 0; j < n; j++) {
                int c_at_j = c[j];
                if (i < c_at_j)
                    continue;
                dp[i] = Math.min(dp[i], dp[i - c_at_j] + 1);
            }
        }

        if (dp[x] != INFINITY)
            System.out.println(dp[x]);
        else
            System.out.println(-1);

        s.close();
    }
}