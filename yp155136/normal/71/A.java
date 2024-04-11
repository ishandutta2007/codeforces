import java.util.Scanner;

public class CF_71A
{
    public static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        for (int ii=0;ii<T;ii++)
        {
            String s = scanner.next();
            int x = s.length();
            if (x<=10)
            {
                System.out.println(s);
            }
            else
            {
                System.out.print(s.charAt(0));
                System.out.print(x-2);
                System.out.println(s.charAt(x-1));
            }
        }
    }
}