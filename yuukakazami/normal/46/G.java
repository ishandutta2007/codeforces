import java.io.*;
import java.util.*;
public class Polygon implements Runnable {
		
	public static void main(String[] args) {
		new Polygon().run();
	}
	
	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;
	
	static class Side implements Comparable<Side>{
		int dx;
		int dy;
		double angle;
		Side next;
		
		Side(){
			
		}
		
		public Side(int dx,int dy){
			this.dx=dx;
			this.dy=dy;
		}
		
		public int compareTo(Side side) {
			return Double.compare(angle, side.angle);
		}
		
		public void getAngle() {
			angle=Math.atan2(dy,dx);
		}
		
		public Side add(Side side){
			return new Side(dx+side.dx,dy+side.dy);
		}
		
		public Side sub(Side side){
			return new Side(dx-side.dx,dy-side.dy);
		}
		

		public int value(){
			return dx*dx+dy*dy;
		}
		
		public boolean check(){
			return dx==0 && dy==0;
		}
	}
	
	public static int Max=500;
	public static int Magic=7;
	List<Side> res;
	Side now;
	public int together(Side a,Side b){
		return a.add(b).value();
	}
	
	
	private void solve()throws IOException{
		int n=nextInt();
		Side first[]=new Side[Max*Max+1];
		for(int dx=-Max;dx<=Max;dx++)
			for(int dy=-Max;dy<=Max;dy++){
				int z=dx*dx+dy*dy;
				if(z<=Max*Max){
					Side s=new Side(dx,dy);
					s.next=first[z];
					first[z]=s;
				}
			}
		int cnt=0;
		List<Side> firsts=new ArrayList<Side>();
		for(int len=1;;len++){
			if(first[len]==null)
				continue;
			++cnt;
			firsts.add(first[len]);
			if(cnt<n)
				continue;
			if(doit(firsts,n))
				break;
		}
		for(Side s:res){
			s.getAngle();
		}
		Collections.sort(res);
		int x=0;
		int y=0;
		writer.println("YES");
		for(Side s:res){
			writer.println(x+" "+y);
			x+=s.dx;
			y+=s.dy;
		}
	}
	
	private boolean doit(List<Side> firsts,int n){
		res=new ArrayList<Side>();
		now=new Side(0,0);
		return rec(firsts,n,firsts.size()-1);
	}
	
	private boolean rec(List<Side> firsts,int rest,int at){
		if(rest==0){
			return now.check();
		}
		if(at>=Magic){
			Side cur=firsts.get(at);
			Side best=cur;
			cur=cur.next;
			while(cur!=null){
				if(together(cur, now)<together(best, now)){
					best=cur;
				}
				cur=cur.next;
			}
			res.add(best);
			now=now.add(best);
			if(rec(firsts,rest-1,at-1))
				return true;
			res.remove(res.size()-1);
			now=now.sub(best);
		}else{
			Side best=firsts.get(at);
			while(best!=null){
				res.add(best);
				now=now.add(best);
				if(rec(firsts,rest-1,at-1))
					return true;
				res.remove(res.size()-1);
				now=now.sub(best);
				best=best.next;
			}
			if(at>=rest)
				if(rec(firsts,rest,at-1))
					return true;
		}
		return false;
	}
	
	public void run(){
		try{
			reader=new BufferedReader(new InputStreamReader(System.in));
			tokenizer=null;
			writer=new PrintWriter(System.out);
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
		while(tokenizer==null || !tokenizer.hasMoreTokens()){
			tokenizer=new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}
}