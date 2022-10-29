import java.util.Scanner;

public class HelloWorld
{
    public static void main(String[] args)
    {
        //System.out.println("Hello, world");
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int x = scanner.nextInt();
        if (x==2 || x%2 == 1)
        {
            System.out.println("NO");
        }
        else
        {
            System.out.println("YES");
        }
    }
}