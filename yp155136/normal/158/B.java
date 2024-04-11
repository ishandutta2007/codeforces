import java.util.Scanner;

public class CF_158B {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int a[] = {0,0,0,0,0};
        for (int i=0;i<n;++i) {
            int x = scanner.nextInt();
            a[x]++;
        }
        int ans=0;
        for (int i=4;i>=1;--i) {
            while (a[i] > 0) {
                ++ans;
                int left = 4-i;
                --a[i];
                for (int j=i;j>=1;--j) {
                    if (j <= left && a[j]>0) {
                        a[j]--;
                        left -= j;
                        j++;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}