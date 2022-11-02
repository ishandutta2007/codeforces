import java.util.*;
import java.io.*;

import javax.swing.RowFilter.Entry;

public class FootBall implements Runnable{
	public static void main(String[] args) {
		new FootBall().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	private void solve() throws IOException{
		Map<String, Integer> map=new HashMap<String, Integer>();
		int n=nextInt();
		for(int i=0;i<n;i++){
			String name=nextToken();
			if(!map.containsKey(name)){
				map.put(name, 1);
			}
			else{
				map.put(name, map.get(name)+1);
			}
		}
		
		String res="";int Max=0;
		
		for(Map.Entry<String, Integer> it:map.entrySet() ){
			if(it.getValue()>Max){
				Max=it.getValue();
				res=it.getKey();
			}
		}
		
		writer.println(res);
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
	
	String nextToken() throws IOException {
		while(tokenizer == null || !tokenizer.hasMoreTokens()){
			tokenizer=new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}