import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner r = new Scanner(System.in);
        String a = r.next(), b = r.next();
        int base = 2;
        for(int i = 0; i < a.length(); i++)
            base = Math.max(base, (a.charAt(i) - '0') + 1);
        for(int i = 0; i < b.length(); i++)
            base = Math.max(base, (b.charAt(i) - '0') + 1);
        int maxN = 0;
        BigInteger n = new BigInteger(a, base);
        BigInteger m = new BigInteger(b, base);
        String ans = (n.add(m)).toString(base);
        maxN = Math.max(ans.length(), maxN);
        System.out.println(maxN);
    }
}