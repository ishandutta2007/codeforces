import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner r = new Scanner(System.in);
        int a = r.nextInt(); int b = r.nextInt();
        String A = BigInteger.valueOf(a).toString(3);
        String B = BigInteger.valueOf(b).toString(3);
        String ans = new String("");
        int temp = Math.abs(B.length() - A.length());
        if(A.length() < B.length()){
            for(int i = 0; i < temp; i++){
                A = '0' + A;
            }
        }
        else {
            for(int i = 0; i < temp; i++){
                B = '0' + B;
            }
        }
        for(int i = 0; i < B.length(); i++){
            char c = (char)(((((B.charAt(i) - '0') - (A.charAt(i) - '0')) + 3) % 3) + '0');
            ans += c;
        }
        System.out.println(new BigInteger(ans, 3));
    }
}