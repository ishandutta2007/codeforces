import java.util.*;
import java.io.*;

public class Cycles implements Runnable{
	public static void main(String[] args) {
		new Cycles().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	private void solve() throws IOException{
		int n=nextInt();
		List<List<Integer> > arrs=new ArrayList<List<Integer> >();
		for(int i=0;i<4;i++)
			arrs.add(new ArrayList<Integer>());
		for(int i=1;i<=n;i++)
			arrs.get(i%4).add(i);
		int cnt=0;
		for(int it=0;it<4;it++){
			cnt+=arrs.get(it).size()*arrs.get((it+1)%4).size();
		}
		writer.println(cnt);
		for(int it=0;it<4;it++){
			for(int a:arrs.get(it)){
				for(int b:arrs.get((it+1)%4)){
					writer.println(a+" "+b);
				}
			}
		}
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