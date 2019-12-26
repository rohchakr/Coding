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
		    long n = s.nextLong();
		    if (n!=0 && ((n&(n-1)) == 0))
		        System.out.println("YES");
	        else
	            System.out.println("NO");
		}
	}
}
