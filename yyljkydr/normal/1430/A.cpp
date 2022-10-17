#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n>=8)
		{
			for(int i=0;i<=4;i++)
				if((n-i*3)%5==0)
				{
					printf("%d %d %d\n",i,(n-i*3)/5,0);
					break;
				}
		}
		else
		{
			if(n==1||n==2||n==4)
				puts("-1");
			else
			{
				if(n==3)
					puts("1 0 0");
				else if(n==5)
					puts("0 1 0");
				else if(n==6)
					puts("2 0 0");
				else if(n==7)
					puts("0 0 1");
			}
		}
	}
}