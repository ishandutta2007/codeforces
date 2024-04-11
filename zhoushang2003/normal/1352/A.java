import java.util.Scanner;
public class O
{
	public static void main(String[] args)
	{
		Scanner S=new Scanner(System.in);
		int t,n,c,s,A[]=new int[5];
		t=S.nextInt();
		while(t-->0)
		{
			n=S.nextInt();
			c=0;
			s=1;
			while(n>0)
			{
				if(n%10>0)
					A[++c]=n%10*s;
				n/=10;
				s*=10;
			}
			System.out.println(c);
			for(int i=1;i<=c;i++)
				System.out.print(A[i]+" ");
			System.out.println();
		}
	}
}