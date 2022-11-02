import java.util.*;
import java.io.*;

public class Tickets implements Runnable{
	public static void main(String[] args) {
		new Tickets().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	private void solve() throws IOException{
		int n=nextInt();
		int[] count=new int[3];
		for(int i=0;i<n;i++){
			int x=nextInt();
			count[x%3]++;
		}
		int ans=0;
		ans+=count[0]/2;
		ans+=Math.min(count[1], count[2]);
		writer.println(ans);
	}
	
	public void run(){
		try{
			reader= new BufferedReader(new InputStreamReader(System.in));
			tokenizer= null;
			writer= new PrintWriter(System.out);
			solve();
			reader.close();
			writer.close();
		} catch(Exception e){
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	int nextInt() throws IOException{
		return Integer.parseInt(nextToken());
	}
	
	long nextLong() throws IOException{
		return Long.parseLong(nextToken());
	}
	double nextDoube() throws IOException{
		return Double.parseDouble(nextToken());
	}
	String nextToken() throws IOException {
		while(tokenizer == null || !tokenizer.hasMoreTokens()){
			tokenizer=new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}