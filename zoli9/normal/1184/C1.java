import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Codeforces {
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        } 
    } 
    public static void main(String[] args) throws Exception{
        FastReader input = new FastReader();
        int n = input.nextInt();
        Point[] points = new Point[4 * n + 1];
        for (int i = 0; i < 4 * n + 1; i++){
            Point p = new Point(input.nextInt(), input.nextInt());
            points[i] = p;
        }
        
        for (int i = 0; i < 51; i++){
            for (int j = i + 1; j < 51; j++){
                for (int k = 0; k < 51; k++){
                    for (int l = k + 1; l < 51; l++){
                        int on = 0;
                        for (int x = 0; x < 4 * n + 1; x++){
                            on += isOn(i, j, k, l, points[x]) ? 1 : 0;
                        }
                        if (on == 4 * n){
                            for (int x = 0; x < 4 * n + 1; x++){
                            if(!isOn(i, j, k, l, points[x])){
                                System.out.println(points[x].x + " " + points[x].y);
                                return;
                            }
                            
                        }
                        }
                    }
                }
            }
        }
    }
    public static boolean isOn(int i, int j, int k, int l, Point p){
        return (i <= p.x && j >= p.x && (p.y == k || p.y == l)) || (k <= p.y && l >= p.y && (p.x == i || p.x == j));
    }
}