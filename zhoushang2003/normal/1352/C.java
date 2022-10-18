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
			System.out.println((k-1)/(n-1)*n+(k-1)%(n-1)+1);
		}
	}
}