import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
    PrintWriter out = new PrintWriter(System.out);
	BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer tok = new StringTokenizer("");
    String next() throws IOException {
        if (!tok.hasMoreTokens()) { tok = new StringTokenizer(in.readLine()); }
        return tok.nextToken();
    }
    int ni() throws IOException { return Integer.parseInt(next()); }
    long nl() throws IOException { return Long.parseLong(next()); }
    int[] na(int n) throws IOException { int[]A=new int[n]; for (int i=0;i<n;i++) A[i]=ni(); return A; }

    void solve() throws IOException {
        long i,ans,last,n,t,L,R,T=0;
        T=nl();
        while(T-->0)
        {
            ans=last=0;
            n=nl();
            L=1;
            R=0;
            for(i=1;i<=n;i++)
            {
                t=nl();
                if(t==1)
                {
                    if(L>0) L=i;
                    if(R==0) R=i;
                }
                else L=R=0;
                if(L>0) ans=-L;
            }
            if(R+ans>0) out.println(R+ans);
            else out.println(0);
            out.flush();
        }
    }

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }
}