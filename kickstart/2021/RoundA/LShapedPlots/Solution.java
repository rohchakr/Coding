import java.util.*;

public class Solution {
  public static void main(String[] args) {
    try (Scanner in = new Scanner(System.in)) {
      int cases = in.nextInt();
      for (int t = 1; t <= cases; t++) {
        // do something
        int rows = in.nextInt();
        int cols = in.nextInt();
        int[][] plot = new int[rows][cols];
        // take plot input
        for (int i = 0; i < rows; i++)
          for (int j = 0; j < cols; j++)
            plot[i][j] = in.nextInt();

        int[][] leftToRight = new int[rows][cols];
        for (int i = 0; i < rows; i++)
          for (int j = 0; j < cols; j++) {
            if (j == 0) {
              leftToRight[i][j] = plot[i][j];
              continue;
            }
            if (plot[i][j] == 1 && plot[i][j - 1] == 1)
              leftToRight[i][j] = leftToRight[i][j - 1] + 1;
            else
              leftToRight[i][j] = plot[i][j];
          }
        
        int[][] rightToLeft = new int[rows][cols];
        for (int i = 0; i < rows; i++)
          for (int j = cols - 1; j >= 0; j--) {
            if (j == cols - 1) {
              rightToLeft[i][j] = plot[i][j];
              continue;
            }
            if (plot[i][j] == 1 && plot[i][j + 1] == 1)
              rightToLeft[i][j] = rightToLeft[i][j + 1] + 1;
            else
              rightToLeft[i][j] = plot[i][j];
          }

        int numLShapes = 0;

        // upToDown
        for (int j = 0; j < cols; j++) {
          int segmentLength = 0;
          for (int i = 0; i < rows; i++) {
            if (plot[i][j] == 1) {
              segmentLength++;
              int num1 = segmentLength;
              int num2 = leftToRight[i][j];
              if (num1 >= 2 && num2 >= 2) {
                numLShapes += Math.min(num1, num2/2) + Math.min(num1/2, num2) - 2; 
              } 
              int num3 = rightToLeft[i][j];
              if (num1 >= 2 && num3 >= 2) {
                numLShapes += Math.min(num1, num3/2) + Math.min(num1/2, num3) - 2; 
              } 
            } else {
              segmentLength = 0;
            }
          }
        }

        // dowmToUp
        for (int j = 0; j < cols; j++) {
          int segmentLength = 0;
          for (int i = rows - 1; i >= 0; i--) {
            if (plot[i][j] == 1) {
              segmentLength++;
              int num1 = segmentLength;
              int num2 = leftToRight[i][j];
              if (num1 >= 2 && num2 >= 2) {
                numLShapes += Math.min(num1, num2/2) + Math.min(num1/2, num2) - 2; 
              } 
              int num3 = rightToLeft[i][j];
              if (num1 >= 2 && num3 >= 2) {
                numLShapes += Math.min(num1, num3/2) + Math.min(num1/2, num3) - 2; 
              } 
            } else {
              segmentLength = 0;
            }
          }
        }

        System.out.println("Case #" + t + ": " + numLShapes);
      }
    }
  }
}
