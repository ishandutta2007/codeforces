#include<stdio.h>
using namespace std;
int i,j,k,l,s,m,n;
int main()
{
	scanf("%d",&n);
	if (n==2)
	{
		printf("%d\n",3);
		return 0;
	}
	for (i=1;i<=1000;i++)
	{
		int j=i;
		int s=0;
		if (j==1)
		s=1;
		else
		if (j==2)
		s=0;
		else
		if (j%2)
		{
			int bb=0;
			int ls=0,rs=0;
			rs=(j/4)*4;
			rs++;
			s=(1+(2*(j/2)+1))*(j/2+1)-(2*(j/2)+1);
			ls=s-rs;
			if (n%2)
			{
				if (rs<3&&(n-1)%4!=0)
				continue;
			}
			else
			{
				if (rs<2&&(n)%4!=0)
				continue;
				s--;
			}
			
		}
		else
		{
			if (j%4==2)
			{
				j-=4;
				j/=2;
			}
			else
			{
				j-=2;
				j/=2;
			}
			s=(j/2)*2-1;
			s*=4;
			if (n%4!=0)
			continue;
		}
		if (s>=n)
		{
			printf("%d\n",i);
			return 0;
		}
	}
}