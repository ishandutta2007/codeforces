import java.util.Scanner;

public class CF_266A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        char c[] = new char[n];
        c = s.toCharArray();
        char last = ' ';
        int ans=0;
        for (int i=0;i<n;i++) {
            if (c[i] == last) {
                ++ans;
            }
            last = c[i];
        }
        System.out.println(ans);
    }
}