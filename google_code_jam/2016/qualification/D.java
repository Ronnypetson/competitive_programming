/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		int t, k, c, s, r;
		Scanner sc = new Scanner(System.in);
		t = sc.nextInt();
		for(int i = 1; i <= t; i++){
			k = sc.nextInt();
			c = sc.nextInt();
			s = sc.nextInt();
			r = (k%c == 0) ? (k/c) : (k/c + 1);
			if(s < r){
				System.out.println("Case #"+i+": IMPOSSIBLE");
				continue;
			}
			BigInteger b[] = new BigInteger[r];
			for(int j = 0; j < r-1; j++){
				b[j] = new BigInteger("1",10);
				for(int k_ = j*c + 1; k_ <= (j+1)*c; k_++){
					BigInteger b_ = new BigInteger(""+k_,10);
					b[j] = b[j].multiply(b_);
				}
			}
			b[r-1] = new BigInteger("1",10);
			for(int k_ = k; k_ >= (k-c) + 1 && k_ >= 1; k_--){
				BigInteger b_ = new BigInteger(""+k_,10);
				b[r-1] = b[r-1].multiply(b_);
			}
			System.out.print("Case #"+i+":");
			for(int j = 0; j < r; j++)
				System.out.print(" " + b[j]);
			System.out.println();
		}
	}
}
