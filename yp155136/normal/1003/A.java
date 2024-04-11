import java.util.Scanner;

public class CF1003A {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        int a[] = new int[106];
        for (int i=0;102>=i;i++) a[i] = 0;
        for (int i=1;n>=i;i++) {
            int x = scanner.nextInt();
            a[x]++;
            if (a[x] > ans) ans = a[x];
            //ans = max(ans,a[x]);
        }
        System.out.println(ans);
    }
}