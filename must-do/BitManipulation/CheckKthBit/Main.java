/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- > 0) {
		    int n = s.nextInt();
		    int k = s.nextInt();
		    if((n & (1<<k)) != 0) {
		        System.out.println("Yes");
		    } else {
		        System.out.println("No");
		    }
		}
	}
}
