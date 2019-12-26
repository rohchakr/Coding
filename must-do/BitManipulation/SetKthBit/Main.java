/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while(t-- > 0) {
		    int n = s.nextInt();
		    int k = s.nextInt();
		    System.out.println(n|(1<<k));
		}
	}
}
