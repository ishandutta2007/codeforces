import java.util.Scanner;

public class CF_158A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int a[] = new int[n];
        for (int i=0;i<n;i++) {
            a[i] = scanner.nextInt();
        }
        int ans = 0;
        for (int i=0;i<n;i++) {
            if (a[i] >= a[k-1] && a[i] > 0) {
                ++ans;
            }
        }
        System.out.println(ans);
    }
}