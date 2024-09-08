import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int m = s.nextInt();
        s.nextLine();
        char[][] c = new char[n][m];
        for (int i = 0; i < n; i++) {
            String line = s.nextLine();
            for (int j = 0; j < m; j++) {
                c[i][j] = line.charAt(j);
            }
        }  

        int rooms = 0;
        LinkedList<Integer> stackX = new LinkedList<>();
        LinkedList<Integer> stackY = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '.') {
                    rooms++;
                    stackX.push(i);
                    stackY.push(j);
                    while(!stackX.isEmpty()) {
                        int x = stackX.pop();
                        int y = stackY.pop();
                        c[x][y] = '#';
                        if (x > 0 && c[x - 1][y] == '.') {
                            stackX.push(x - 1);
                            stackY.push(y);
                        }
                        if (x + 1 < n && c[x + 1][y] == '.') {
                            stackX.push(x + 1);
                            stackY.push(y);
                        }
                        if (y > 0 && c[x][y - 1] == '.') {
                            stackX.push(x);
                            stackY.push(y - 1);
                        }
                        if (y + 1 < m && c[x][y + 1] == '.') {
                            stackX.push(x);
                            stackY.push(y + 1);
                        }
                    }
                }
            }
        }
        System.out.println(rooms);  
    }
}