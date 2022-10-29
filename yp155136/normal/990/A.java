import java.util.Scanner;

public class CF_990A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        long a = scanner.nextLong();
        long b = scanner.nextLong();
        long ans1 = (n%m)*b;
        long ans2 = (m-n%m)*a;
        if (ans1 > ans2) System.out.println(ans2);
        else System.out.println(ans1);
    }
}