import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long n = s.nextLong();
        while (true) {
            if (n == 1) {
                System.out.println(1);
                break;
            }
            System.out.print(n + " ");
            n = (n % 2 == 0) ? (n / 2) : (n * 3) + 1;
        }
    }
}