import java.util.Scanner;
import java.math.BigInteger;

public final class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            String as = sc.next();
            String bs = sc.next();
            BigInteger a = new BigInteger(as);
            BigInteger b = new BigInteger(bs);
            a = a.multiply(a);
            b = b.multiply(b);
            BigInteger c = a.subtract(b);
            if (c.isProbablePrime(100)) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
    }
}