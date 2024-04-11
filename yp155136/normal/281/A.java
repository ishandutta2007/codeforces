import java.util.Scanner;

public class CF_281A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        char c[] = s.toCharArray();
        int n = s.length();
        for (int i=0;i<n;++i) {
            if (i == 0) {
                if (c[i] <= 'z') {
                    char cc = Character.toUpperCase(c[i]);
                    System.out.print(cc);
                }
                else {
                    System.out.print(c[i]);
                }
            }
            else {
                System.out.print(c[i]);
            }
        }
        System.out.print('\n');
    }
}