import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long MOD = 1000000007;
        int n = s.nextInt();

        long[] dp = new long[n + 1];

        // base case
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i < j)
                    break;
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }

        System.out.println(dp[n]);
        s.close();
    }
}