import java.util.Scanner;
public class O
{
	public static void main(String[] args)
	{
		Scanner S=new Scanner(System.in);
		int t,n,k;
		t=S.nextInt();
		while(t-->0)
		{
			n=S.nextInt();
			k=S.nextInt();
			if(n%2==k%2&&n>=k)
			{
				System.out.println("YES");
				for(int i=1;i<k;i++)
					System.out.print(1+" ");
				System.out.println(n-k+1);
			}
			else if(n%2==0&&n>=2*k)
			{
				System.out.println("YES");
				for(int i=1;i<k;i++)
					System.out.print(2+" ");
				System.out.println(n-2*k+2);
			}
			else
				System.out.println("NO");
		}
	}
}