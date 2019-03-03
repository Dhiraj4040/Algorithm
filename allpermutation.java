//Given a string S. The task is to print all permutations of a given string.

import java.util.*;
import java.lang.*;
import java.io.*;

class allpermutation {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while(t-->0){
			String s1=br.readLine();
            char[] c=s1.toCharArray();
              int len=c.length;
               findpermutation(c,0,len);			  
           }
	}
	
	static boolean shouldswap(char[] c,int start,int curr){
		for(int i=start;i<curr;i++){
			if(c[i]==c[curr]){
				return false;
			}
		}
		return true;		
    }
	 
	 static void swap(char[] c,int i,int j){
		 char ch=c[i];
		 c[i]=c[j];
		 c[j]=ch;
	 }
	 
	static void findpermutation(char[] c,int index,int n){
		if(index>=n){
			System.out.println(c);
			return;
		}
		for(int i=index;i<n;i++){
			boolean check = shouldswap(c, index, i); 
            if (check) { 
                swap(c, index, i); 
                findpermutation(c, index + 1, n); 
                swap(c, index, i); 
            } 
		}
	}
}
