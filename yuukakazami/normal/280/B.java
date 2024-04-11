import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // write your code here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) {
            rev[i] = a[n - 1 - i];
        }
        System.out.println(Math.max(doIt(a), doIt(rev)));
    }

    private static int doIt(int a[]) {
        int n = a.length;
        int[] stack = new int[n];
        int top = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (top > 0 && stack[top - 1] < a[i]) {
                ans = Math.max(ans, stack[--top] ^ a[i]);
            }
            stack[top++] = a[i];
        }
        return ans;
    }
}