import java.util.Scanner;

public class CF_994A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[10];
        for (int i=0;i<n;++i) {
            a[i] = scanner.nextInt();
        }
        for (int i=0;i<m;i++) {
            int x = scanner.nextInt();
            b[x] = 1;
        }
        for (int i=0;i<n;++i) {
            if (b[ a[i] ] == 1) {
                System.out.print(a[i]);
                System.out.print(' ');
            }
        }
    }
}