import java.util.Scanner;

public class CF_1A
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        long a = s.nextInt();
        long b = s.nextInt();
        long c = s.nextInt();
        System.out.println(((a+c-1)/c)*((b+c-1)/c));
    }
}